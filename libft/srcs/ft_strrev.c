#include "libft.h"

/*
**	return a new reversed copy of s.
*/
char		*ft_strrev(const char *s)
{
	char	*rev;
	int		i;
	int		c;

	i = 0;
	if (!s)
		return (NULL);
	c = ft_strlen(s);
	rev = ft_strnew(c);
	while (rev && c >= 0)
		rev[i++] = s[--c];
	rev[i] = '\0';
	return (rev);
}
