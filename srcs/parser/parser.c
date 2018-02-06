#include "parser.h"

static int	detect_simple_cmd(t_token *l)
{
	int		c;

	c = 0;
	while (l && l->type != OPERATOR_T)
	{
		l = l->next;
		c++;
	}
	if (c == 0 && l == NULL)
		return (-1);
	return (c);
}

static int	setup_argv(t_scmd *scmd, t_token **tokens, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		scmd->argv[i++] = ft_strdup((*tokens)->value);
		*tokens = (*tokens)->next;
	}
	scmd->argv[i] = NULL;
	return (DONE);
}

static int	setup_stream_names(t_scmd *whole_scmd, t_scmd *scmd, char *pre, char *post)
{
	t_scmd	*whole;
	t_scmd	*scommand;

	whole = whole_scmd;
	if (pre)
	{
		if (0 == ft_strcmp("|", pre))
			scmd->input = ft_strdup("|");

		else if (0 == ft_strcmp(">", pre))
		{
			if (whole_scmd == NULL || scmd->argv == NULL)
				return (ret_error("Parse", "Error near '>'", ERR));
			while (whole->next)
				whole = whole->next;
			whole->output = ft_strdup(scmd->argv[0]);
			return (NO_APPEND);
		}

		else if (0 == ft_strcmp("<", pre))
		{
			if (whole_scmd == NULL || scmd->argv == NULL)
				return (ret_error("Parse", "Error near '<'", ERR));
			whole_scmd->open_flags = O_TRUNC | O_WRONLY | O_CREAT;
			whole_scmd->input = ft_strdup(scmd->argv[0]);
			return (NO_APPEND);
		}

		else if (0 == ft_strcmp(">>", pre))
		{
			if (whole_scmd == NULL || scmd->argv == NULL)
				return (ret_error("Parse", "Error near '<<'", ERR));
			while (whole->next)
				whole = whole->next;
			whole->open_flags = O_APPEND | O_WRONLY | O_CREAT;
			whole->output = ft_strdup(scmd->argv[0]);
			return (NO_APPEND);
		}
	}
	if (post)
	{
		if (0 == ft_strcmp("|", pre))
			scmd->output = ft_strdup("|");
	}
	return (DONE);
}

/*
**	Parser: parse the token struct and split commamnd
**	into simple commands.
*/
t_cmd		*parser(t_token *line)
{
	t_token	*l;
	t_cmd	*head;
	t_cmd	*cmd;
	t_scmd	*simple_cmd;
	int		count;
	int		i;
	char		*pre_operator;
	char		*post_operator;

	l = line;
	head = NULL;
	while (1)
	{
		if ((cmd = new_cmd()) == NULL)
		{
			ret_error("#1 parser", "Not enough memory.", ERR);
			purge_cmd(cmd);
			return (NULL);
		}

		pre_operator = NULL;
		post_operator = NULL;
		while ((count = detect_simple_cmd(l)) != -1)
		{
			if ((simple_cmd = new_scmd()) == NULL || \
				(simple_cmd->argv = \
					(char **)malloc(sizeof(char *) * (count + 1))) == NULL)
			{
				ret_error("#2 parser", "Not enough memory.", ERR);
				purge_scmd(cmd->by_one);
				purge_cmd(cmd);
				return (NULL);
			}

			setup_argv(simple_cmd, &l, count);

			pre_operator = post_operator;
			post_operator = l ? l->value : NULL;
			if (l)
				l = l->next;

			if (setup_stream_names(cmd->by_one, simple_cmd, pre_operator, post_operator) != NO_APPEND)
			{
				if ((cmd->by_one = add_scmd(cmd->by_one, simple_cmd)) == NULL)
				{
					purge_scmd(cmd->by_one);
					purge_cmd(cmd);
					return (NULL);
				}
			}
			else
				destroy_scmd(&simple_cmd);

			if (0 == ft_strcmp(post_operator, ";"))
				break ;
		}
		head = add_cmd(head, cmd);
		if (count == -1 || l == NULL)
			break ;
	}
	return (head);
}
