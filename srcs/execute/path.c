#include "execute.h"

char		*search_in_path(char *name)
{
	char	**path;
	char	*search;
	int		i;

	i = 0;
	search = NULL;
	path = ft_strsplit(getenv("PATH"), ':');
	while (path[i])
	{
		path[i] = ft_straddch(path[i], '/');
		search = ft_strjoin(path[i], name);
		if (access(search, F_OK) == 0)
			break ;
		ft_strdel(&search);
		i++;
	}
	ft_2dstrdel(path);
	return (search);
}
