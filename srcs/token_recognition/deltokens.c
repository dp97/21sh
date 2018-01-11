#include "tokening.h"

void		ft_deltokens(t_token **tokens)
{
	t_token	*del;

	while (*tokens)
	{
		del = *tokens;
		*tokens = (*tokens)->next;
		ft_strdel(&del->value);
		free(del);
	}
}
