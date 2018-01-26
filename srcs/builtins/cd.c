#include "builtins.h"

char		*ft_assemblepath(char **comp, int count)
{
	char	*path;
	char	*temp;
	int		size;
	int		i;

	size = 0;
	while (i < count)
	{
		temp = path;
		if (comp[i])
		{
			path = ft_strjoin(path, comp[i]);
			ft_strdel(&temp);
		}
		++i;
	}
	return (path);
}

char 		*ft_tocanonform(char *path)
{
	char	**components;
	char	*component;
	int		i;
	int		c;

	i = 0;
	components = ft_strsplit(path, '/');
	while (components[i])
	{
		component = components[i++];
		if (ft_strcmp(component, ".") == 0)
			ft_strdel(&component);
		else if (ft_strcmp(component, "..") == 0)
		{
			c = i;
			while (c > 0 && components[--c] == NULL)
				;
			if (c >= 0)
			{
				ft_strdel(&components[c]);
				ft_strdel(&component);
			}
		}
	}
	ft_strdel(&path);
	return (ft_assemblepath(components, i));
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

	if (operand == NULL && home == NULL)//1
		return (DONE);
	if (operand == NULL && home)//2
		curpath = ft_strdup(home);
	if (operand[0] == '/')//3
		curpath = ft_strdup(operand);//goto 7
	if (ft_strncmp(operand, "..", 2) == 0 || ft_strncmp(operand, ".", 1) == 0)//4
		;//nan goto 6
	curpath = pathcat(pwd, operand);//6
	curpath = ft_tocanonform(curpath);//8
	if (chdir(curpath))//9
	{
		perror("ww");
		return (ret_error("chdir", curpath, ERR));
	}
	ft_setenv("OLDPWD", pwd, 1);
	ft_setenv("PWD", curpath, 1);
	ft_strdel(&curpath);
	return (DONE);
}
