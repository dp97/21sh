#include "builtins.h"

static char		*ft_assemblepath(char **comp, int count)
{
	char	*path;
	char	*temp;
	int		size;
	int		i;

	size = 0;
	path = NULL;
	while (i < count)
	{
		if (comp[i] != NULL)
		{
			temp = path;
			path = ft_strjoin(path, "/");
			ft_strdel(&temp);
			temp = path;
			path = ft_strjoin(path, comp[i]);
			ft_strdel(&temp);
		}
		++i;
	}
	return (path);
}

static char 		*ft_tocanonform(char *path)
{
	char	**components;
	char	*cpath;
	int		curr;
	int		prev;

	if (!path)
		return (NULL);
	curr = 0;
	components = ft_strsplit(path, '/');
	while (components[curr])
	{
		if (ft_strcmp(components[curr], ".") == 0)
			ft_strdel(&components[curr]);
		else if (ft_strcmp(components[curr], "..") == 0)
		{
			prev = curr;
			while (--prev >= 0)
			{
				if (components[prev])
				{
					if (components[prev])
						ft_strdel(&components[prev]);
					if (components[curr])
						ft_strdel(&components[curr]);
					break ;
				}
			}
		}
		curr++;
	}
	ft_strdel(&path);
	cpath = ft_assemblepath(components, curr);
	free(components);
	return (cpath ? cpath : ft_strdup("/"));
}

int	builtin_cd(char **cmd, char **env)
{
	char	*operand;
	char	*curpath;
	char	*pwd;
	char	*home;

	curpath = NULL;
	operand = cmd[1];
	home = getenv("HOME");
	if ((pwd = getenv("PWD")) == NULL)
		return (ret_error("cd", "Failed to get 'PWD' env.", ERR));
	if (operand == NULL && home == NULL)
		return (DONE);
	if (operand == NULL && home)
		curpath = ft_strdup(home);
	else if (ft_strcmp(operand, "-") == 0)
	{
		curpath = ft_strdup(getenv("OLDPWD"));
		ft_putendl(curpath);
	}
	else if (operand[0] == '/')
		curpath = ft_strdup(operand);
	else
		curpath = pathcat(pwd, operand);
	curpath = ft_tocanonform(curpath);
	if (chdir(curpath))
	{
		perror(operand);
		ft_strdel(&curpath);
		return (ERR);
	}
	ft_setenv("OLDPWD", pwd, 1);
	ft_setenv("PWD", curpath, 1);
	ft_strdel(&curpath);
	return (DONE);
}
