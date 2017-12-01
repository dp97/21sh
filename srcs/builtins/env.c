/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:15:43 by dpetrov           #+#    #+#             */
/*   Updated: 2017/02/22 13:59:31 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_getenv(char *name, char **env)
{
	int		i;
	int		len;

	i = 0;
	while (env[i])
	{
		len = ft_strlen(name);
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
		{
			return (&env[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

int			ft_printenv(char **args, char **env)
{
	int		i;
	int		len;

	i = 0;
	while (env[i])
	{
		len = ft_strlen(args[1]);
		if (ft_strncmp(env[i], args[1], len) == 0)
		{
			ft_putendl_fd(&env[i][len + 1], STDOUT_FILENO);
			return (0);
		}
		i++;
	}
	return (1);
}

int			ft_env(char **args, char **env)
{
	int		i;

	i = 0;
	(void)args;
	while (env[i])
	{
		ft_putendl_fd(env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}

int			ft_unsetenv(char **args, char **env)
{
	int		i;
	int		len;

	i = 0;
	if (args[1] == NULL)
		ft_putendl_fd("unsetenv: Too few arguments.", STDERR_FILENO);
	else
	{
		while (env[i])
		{
			len = ft_strlen(args[1]);
			if (ft_strncmp(env[i], args[1], len) == 0)
			{
				while (env[i])
				{
					env[i] = env[i + 1];
					i++;
				}
			}
			i++;
		}
		return (0);
	}
	return (1);
}
