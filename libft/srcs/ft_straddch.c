#include "libft.h"

char		*ft_straddch(char *s, char c)
{
	char	*new;
	int		l;

	l = ft_strlen(s);
	if ((new = (char *)malloc(sizeof(char) * (l + 2))) == NULL)
		return (NULL);
	if (s)
		ft_strcpy(new, s);
	new[l++] = c;
	new[l] = '\0';
	ft_strdel(&s);
	return (new);
}
