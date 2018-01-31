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

int		execute_cmd(char **cmds, char **env)
{
	char	*cmd_name;
	char	*in_path;
	int		ret_code;

	cmd_name = *cmds;
	ret_code = 0;
	if (ft_strchr(cmd_name, '/') == NULL)
	{
		if ((ret_code = search_in_builtin(cmd_name, cmds, env)) != NO_MATCH)
			;
		else if (0)
			;// case b
		else if (0)
			;// case c
		else
		{
			if ((in_path = search_in_path(cmd_name)) != NULL)
				ret_code = ft_execve(in_path, cmds, env);
			else
				return (ret_error(cmd_name, "Command not found.", 127));
		}
	}
	else
		;
	return (ret_code);
}

int			execute(t_cmd *cmds, char **env)
{
	t_cmd	*cmd;
	char	**argv;
	int		ret_code;

	ret_code = 0;
	cmd = cmds;
	while (cmd)
	{
		ft_putstr("[A]");
		if (cmd->by_one)
			argv = cmd->by_one->argv;
ft_putstr("[B]");
		ft_put2str(argv, '+');

		//decomplex_the_command(argv);
		ret_code = execute_cmd(argv, env);
		cmd = cmd->next;
	}
	return (ret_code);
}
