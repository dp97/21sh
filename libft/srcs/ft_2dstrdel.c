#include "libft.h"

void		ft_2dstrdel(char **as)
{
	int		i;

	i = 0;
	while (as[i])
	{
		free(as[i]);
		as[i++] = NULL;
	}
	free(as);
}
