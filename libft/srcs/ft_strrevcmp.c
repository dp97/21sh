#include "libft.h"

/*
**	Compares the two strings s1 and s2 from end to start index.
**	RETURNS:	- .. s1 < s2
**				0 .. s1 = s2
**				+ .. s2 > s2
*/
int			ft_strrevcmp(const char *s1, const char *s2)
{
	char	*r1;
	char	*r2;
	int		ret;

	r1 = ft_strrev(s1);
	r2 = ft_strrev(s2);
	ret = ft_strcmp(r1, r2);
	ft_strdel(&r1);
	ft_strdel(&r2);
	return (ret);
}
