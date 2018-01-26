#include "minishell.h"

/*
**	Concatenate a path, a slash and name.
*/
char		*pathcat(char *p, char *n)
{
	char	*c;

	if ((c = ft_strnew(sizeof(char) * \
			(ft_strlen(p) + ft_strlen(n) + 1))) == NULL)
		return (NULL);
	ft_strcat(c, p);
	ft_strcat(c, "/");
	ft_strcat(c, n);
	return (c);
}
