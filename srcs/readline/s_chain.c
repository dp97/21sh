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
**
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
