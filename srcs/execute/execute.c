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

#include "execute.h"

int			execute(char **cmds, char **env)
{
	char	**argv;
	char	*exec;
	char *cmd_name;
	int		ret_code;

	ret_code = 0;
	argv = cmds;
	cmd_name = *argv;
	if (ft_strchr(cmd_name, '/') == NULL)
	{
		if ((ret_code = search_in_builtin(cmd_name, argv)) != NO_MATCH)
			free(argv);
		else if (0)
			;// case b
		else if (0)
			;// case c
		else
		{
			if ((exec = search_in_path(cmd_name)) != NULL)
				ret_code = ft_execve(exec, argv, env);
			else
				return (ret_error(cmd_name, "Command not found.", 127));
		}
	}
	else
		;
	return (ret_code);
}
