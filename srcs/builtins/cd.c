/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 09:43:02 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/04 13:48:49 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "free_mem.h"

static char	*cd_error(char *path)
{
	struct stat path_stat;

	if (access(path, F_OK))
		return (": no such file or directory.");
	else
	{
		stat(path, &path_stat);
		if (S_ISREG(path_stat.st_mode))
			return (": not a directory.");
		else if (access(path, R_OK) || access(path, X_OK))
			return (": permission denied.");
	}
	return (0);
}

void		ft_home_path(char *args, char *home, char *next_path, int *len)
{
	if (ft_strcmp(args, "~") == 0)
	{
		(*len) = ft_strlen(home);
		ft_memcpy(next_path, home, *len + 1);
	}
	else
	{
		if ((ft_strncmp(args, "~/", 2)) == 0)
		{
			(*len) = ft_strlen(home);
			ft_memcpy(next_path, home, *len + 1);
			args += 2;
		}
		ft_memcpy(&next_path[(*len)], args, ft_strlen(args) + 1);
	}
}

void		if_spaced(char *args, char *next_path, int len)
{
	if (args != NULL)
	{
		len = ft_strlen(next_path);
		ft_memcpy(&next_path[len], "/", 1);
		ft_memcpy(&next_path[len + 1], args, ft_strlen(args) + 1);
		ft_printf("%s\n", next_path);
	}
}

static int	save_wd(char **env)
{
	char	*pwd[4];
	char	*oldpwd[4];
	int		i;

	oldpwd[0] = ft_strdup("setenv");
	oldpwd[1] = ft_strdup("OLDPWD");
	oldpwd[2] = ft_strdup(ft_getenv("PWD", env));
	oldpwd[3] = NULL;
	pwd[0] = ft_strdup("setnenv");
	pwd[1] = ft_strdup("PWD");
	pwd[2] = getcwd(pwd[2], 0);
	pwd[2] = getcwd(pwd[2], sizeof(pwd[2]));
	pwd[3] = NULL;
	ft_setenv(oldpwd, env);
	ft_setenv(pwd, env);
	i = 0;
	while (i < 4)
	{
		free(pwd[i]);
		free(oldpwd[i]);
		++i;
	}
	return (1);
}

int			ft_cd(char **args, char **env)
{
	char	*home;
	char	next_path[PATH_MAX];
	int		len;

	if (args[1] && args[2] && args[3] != NULL)
		return (ft_error("cd: Too many arguments."));
	home = ft_getenv("HOME", env);
	len = 0;
	if (args[1] != NULL)
	{
		ft_home_path(args[1], home, next_path, &len);
		if_spaced(args[2], next_path, len);
		if (chdir((ft_strcmp(args[1], "-") == 0) ? \
					ft_getenv("OLDPWD", env) : next_path) != 0)
			return (check_error(next_path, cd_error(next_path)));
		save_wd(env);
	}
	else
	{
		if (home == NULL || cd_error(home))
			return (ft_error("cd: Can't change to home directory."));
		chdir(home);
		save_wd(env);
	}
	return (0);
}
