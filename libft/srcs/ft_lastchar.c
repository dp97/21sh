#include "libft.h"

char	ft_lastchar(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ('\0');
	while (s[i])
		i++;
	return (i == 0 ? s[i] : s[i - 1]);
}
