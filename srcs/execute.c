/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:10:34 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/01 16:50:32 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_execute(char **args, char **env, t_cmd *history)
{
	int		ret;

	if (args[0] == NULL)
		return (1);
	if (strcmp(args[0], "exit") == 0)
		return (ft_exit(args));
	else if (strcmp(args[0], "cd") == 0)
		ret = ft_cd(args, env);
	else if (strcmp(args[0], "echo") == 0)
		ret = ft_echo(&args);
	else if (strcmp(args[0], "env") == 0)
		ret = ft_env(args, env);
	else if (strcmp(args[0], "setenv") == 0)
		ret = ft_setenv(args, env);
	else if (strcmp(args[0], "unsetenv") == 0)
		ret = ft_unsetenv(args, env);
	else if (strcmp(args[0], "printenv") == 0)
		ret = ft_printenv(args, env);
	else if (strcmp(args[0], "history") == 0)
		ret = ft_history(&history);
	else if (strcmp(args[0], ":") == 0)
		return (1);
	else
		ret = ft_launch(args, env);
	return (1);
}
