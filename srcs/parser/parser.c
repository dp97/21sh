#include "parser.h"

static int	detect_simple_cmd(t_token *l)
{
	int		c;
	char	*tmp;
	t_token	*prevt;

	c = 0;
	while (l && l->type != OPERATOR_T)
	{
		prevt = l;
		l = l->next;
		c++;

		if (l && l->next && ft_strlen(l->value) == 1 && \
						l->next->type == OPERATOR_T && \
						ft_strchr("><", l->next->value[0]) && \
						ft_strchr("0123456789", l->value[0]))
		{
			tmp = ft_strjoin(l->value, l->next->value);
			prevt->next = l->next;
			ft_strdel(&(l->value));
			free(l);
			l = prevt->next;
			ft_strdel(&(l->value));
			l->value = tmp;
		}
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

			if (prep_redir(cmd->by_one, simple_cmd, pre_operator, post_operator) != NO_APPEND)
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
