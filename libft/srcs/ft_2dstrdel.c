#include "libft.h"

void		ft_2dstrdel(char **as)
{
	int		i;

	i = 0;
	if (as == NULL)
		return ;
	while (as[i])
	{
		free(as[i]);
		as[i++] = NULL;
	}
	free(as);
	as = NULL;
}
