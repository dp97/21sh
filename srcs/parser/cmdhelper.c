#include "parser.h"

t_cmd		*new_cmd(void)
{
    t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new)
	{
		new->by_one = NULL;
		new->next = NULL;
	}
	return (new);
}

t_cmd	*add_cmd(t_cmd *head, t_cmd *new)
{
	t_cmd	*tmp;

	if (head == NULL)
		return (new);
	tmp = head;
	while (head->next)
		head = head->next;
	head->next = new;
	return (tmp);
}
