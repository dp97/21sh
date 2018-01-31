#include "parser.h"

static int	detect_simple_cmd(t_token *l, int *flag)
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
	if (l && 0 == ft_strcmp(l->value, ";"))
		*flag = SEPARATOR;
	else if (l && 0 == ft_strcmp(l->value, "|"))
		*flag = PIPE;
	else if (l && 0 == ft_strcmp(l->value, "<"))
		*flag = IN;
	else if (l && 0 == ft_strcmp(l->value, "<<"))
		*flag = DIN;
	else if (l && 0 == ft_strcmp(l->value, ">"))
		*flag = OUT;
	else if (l && 0 == ft_strcmp(l->value, ">>"))
		*flag = DOUT;
	else
		*flag = -1;
	return (c);
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
	int		prev_flag;
	int		flag;

	l = line;
	head = NULL;
	while (1)
	{
		cmd = new_cmd();
		flag = -1;
		prev_flag = -1;
		while ((count = detect_simple_cmd(l, &flag)) != -1)
		{
			simple_cmd = new_scmd();
			simple_cmd->argv = (char **)malloc(sizeof(char *) * (count + 1));
			i = 0;
			while (i < count)
			{
				simple_cmd->argv[i++] = ft_strdup(l->value);
				l = l->next;
			}
			simple_cmd->argv[i] = NULL;
			if (l)
				l = l->next;
			if ((cmd->by_one = add_scmd(cmd->by_one, simple_cmd, prev_flag)) == NULL)
				return (NULL);
			if ((prev_flag = flag) == SEPARATOR)
				break ;
		}
		head = add_cmd(head, cmd);
		if (count == -1 || l == NULL)
			break ;
	}
	return (head);
}
