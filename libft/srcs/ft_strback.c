#include "libft.h"

/*	returns char numbered from end to start of the string at 'at' position.
**	if not in string then '0' is returned.
*/
char	ft_strback(char *s, int at)
{
	int	pos;

	if (s == NULL)
		return (0);
	pos = ft_strlen(s) - at;
	if (pos < 0)
		return (0);
	return (s[pos]);
}
