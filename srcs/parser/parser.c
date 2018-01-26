#include "parser.h"

static void	ft_append(t_cmd **head, t_cmd *cmd)
{
	t_cmd	*t;

	if (*head == NULL)
	{
		*head = cmd;
		return ;
	}
	t = *head;
	while (t->next)
		t = t->next;
	t->next = cmd;
}

static int	count_argc(t_token **l)
{
	t_token	*t;
	int		c;

	c = 0;
	while (*l && ft_strcmp((*l)->value, ";") == 0)
		*l = (*l)->next;
	t = *l;
	while (t && ft_strcmp(t->value, ";"))
	{
		c++;
		t = t->next;
	}
	return (c);
}

t_cmd		*parser(t_token *line)
{
	t_token	*l;
	t_cmd	*head;
	t_cmd	*cmds;
	char	**val;
	int		argc;
	int		i;

	cmds = NULL;
	l = line;
	head = NULL;
	while (l)
	{
		i = 0;
		if ((argc = count_argc(&l)) == 0)
			continue ;
		if ((val = (char **)malloc(sizeof(char *) * (argc + 1))) == NULL)
			return (NULL);
		while (i < argc)
		{
			val[i++] = l->value;
			l = l->next;
		}
		val[i] = NULL;
		if ((cmds = (t_cmd *)malloc(sizeof(t_cmd))) == NULL)
			return (NULL);
		cmds->value = val;
		cmds->next = NULL;
		ft_append(&head, cmds);
	}
	return (head);
}
