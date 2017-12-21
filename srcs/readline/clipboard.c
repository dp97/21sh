#include "ft_readline.h"

/*
**	HOLD MY CHAR
**		- Alternative to Global variables.
**	if assign is non 0 then  value is assigned to it.
*/
char	*clipboard(char *s, short assign)
{
	static char	*here;

	if (assign == 1)
	{
		ft_strdel(&here);
		here = s;
	}
	return (here);
}

