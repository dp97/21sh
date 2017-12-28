#include "execute.h"

int			search_in_path(char *name)
{
	char	**path;
	char	*search;
	int		i;

	i = 0;
	path = ft_strsplit(getenv("PATH"), ':');
	while (path[i])
	{
		path[i] = ft_straddch(path[i], '/');
		search = ft_strcat(path[i], name);
		i++;
	}
	return (NO_MATCH);
}
