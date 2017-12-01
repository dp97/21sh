/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:02:11 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/01 16:14:50 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_error(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	return (1);
}

static void	setenv_loop(char **env, char **args, int *i, int la)
{
	while (env[*i])
	{
		if (ft_strncmp(env[*i], args[1], la) == 0)
		{
			env[*i] = NULL;
			break ;
		}
		if (env[++(*i)] == NULL)
			env[(*i) + 1] = NULL;
	}
}

#define VNMCAC ("setenv: Variable name must contain alphanumeric characters.")

int			check_alpha(char *arg)
{
	int		i;

	i = 0;
	if (arg && (ft_isdigit(arg[0])))
		return (ft_error("setenv: Variable name must begin with a letter."));
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0 && ft_isalpha(arg[i]) == 0)
			return (ft_error(VNMCAC));
		++i;
	}
	return (0);
}

int			ft_setenv(char **args, char **env)
{
	int		i;
	int		la;
	int		lb;

	i = 0;
	if (check_alpha(args[1]))
		return (1);
	if (args[1])
	{
		la = ft_strlen(args[1]);
		lb = (args[2] != NULL) ? ft_strlen(args[2]) : 0;
		setenv_loop(env, args, &i, la);
		if ((env[i] = (char *)malloc(sizeof(char) * (la + lb + 2))) == NULL)
			return (ft_error("malloc: Not enough space."));
		ft_strcpy(env[i], args[1]);
		ft_strcpy(&env[i][la++], "=");
		if (args[2])
			ft_strcpy(&env[i][la], args[2]);
		env[i][la + lb] = '\0';
	}
	else
		ft_env(args, env);
	return (0);
}
