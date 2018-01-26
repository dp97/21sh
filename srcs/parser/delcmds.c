#include "parser.h"

/*
**	actual strings from value was freed by ft_deltokens!!!
*/
void		ft_delcmds(t_cmd **cmds)
{
	t_cmd	*del;

	while (*cmds)
	{
		del = *cmds;
		*cmds = (*cmds)->next;
		free(del->value);
		free(del);
	}
}
