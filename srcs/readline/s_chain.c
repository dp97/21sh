#include "ft_readline.h"

/*
**	Create a new struct of type s_chain and return it.
**	On error NULL is returned.
*/
t_chain		*ft_chainnew(char *value)
{
	t_chain	*new;

	if ((new = (t_chain *)malloc(sizeof(t_chain))) == NULL)
		return (NULL);
	if (value)
	{
		if ((new->value = ft_strdup(value)) == NULL)
		{
			free(new);
			return NULL;
		}
	}
	else
		new->value = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

/*
**	Append a new s_chain struct with value to NULL.
**	and head pointer is moved to newly created element.
*/
int			ft_chainadd_front(t_chain **head)
{
	t_chain	*tmp;

	if ((tmp = *head) == NULL)
		return (((*head = ft_chainnew(NULL)) ? DONE : ERR));
	else
	{
		while (tmp->prev)
			tmp = tmp->prev;
		if ((tmp->prev = ft_chainnew(NULL)) == NULL)
			return (ERR);
		tmp->prev->next = tmp;
		*head = tmp->prev;
	}
	return (DONE);
}

/*
**	Prepend a new s_chain struct with value to NULL.
**	and head pointer is moved to newly created element.
*/
int			ft_chainadd_back(t_chain **head)
{
	t_chain	*tmp;

	if ((tmp = *head) == NULL)
		return (((*head = ft_chainnew(NULL)) ? DONE : ERR));
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if ((tmp->next = ft_chainnew(NULL)) == NULL)
			return (ERR);
		tmp->next->prev = tmp;
		*head = tmp->next;
	}
	return (DONE);
}

/*
**	Delete/frees all nodes of s_chain struct.
*/
void		ft_chainpurge(t_chain **chain)
{
	t_chain	*tmp;

	while (*chain)
	{
		tmp = *chain;
		*chain = (*chain)->next;
		tmp->next = NULL;
		tmp->prev = NULL;
		ft_strdel(&tmp->value);
		free(tmp);
	}
}
