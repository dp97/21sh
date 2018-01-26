#include "execute.h"

char		*search_in_path(char *name)
{
	char	**path;
	char	*search;
	int		i;

	if (!name)
		return (NULL);
	i = 0;
	search = NULL;
	if ((path = ft_strsplit(getenv("PATH"), ':')) == NULL)
		return (NULL);
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
