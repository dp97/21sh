#include "parser.h"

/*
**	actual strings from value was freed by ft_deltokens!!!
*/
void		ft_delcmds(t_cmd **cmds)
{
	t_cmd	*t;

	while (*cmds)
	{
		t = *cmds;
		*cmds = (*cmds)->next;
		free(t->value);
		free(t);
	}
}
