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

int		search_and_run(char **cmds, char **env)
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

int			execute_scmd(t_scmd *scmd, char **env)
{
	t_scmd	*command;
	char	**argv;
	int		ioe[3];

	command = scmd;
	ioe[0] = INVALID_FD;
	ioe[1] = INVALID_FD;
	while (command)
	{
		argv = command->argv;

		if (command->ioe[1] == TO_PIPE)
			ioe[1] = TO_PIPE;
		else if (command->ioe[1] == TO_FILE || command->ioe[1] == ATO_FILE)
		{
			if (command->next == NULL)
				return (ERR);
			if ((ioe[1] = get_file(command->next->argv[0], command->ioe[1])) == -1)
				return (ERR);
		}
/*
	TODO:
	- Make redirection so that before executing the whole command.
*/
		if (command->ioe[0] != INVALID_FD || command->ioe[1] != INVALID_FD)
		{
			if (get_input_from(ioe, argv, env) == EXIT)
				return (EXIT);
		}
		else
			if (search_and_run(argv, env) == EXIT)
				return (EXIT);
		command = command->next;
	}
	return (DONE);
}

int			execute(t_cmd *cmds, char **env)
{
	t_cmd	*cmd;
	int		ret_code;

	ret_code = 0;
	cmd = cmds;
	while (cmd)
	{
		ret_code = execute_scmd(cmd->by_one, env);
		if (ret_code == EXIT)
			return (EXIT);
		else if (ret_code == ERR)
			return (ERR);
		cmd = cmd->next;
	}
	return (ret_code);
}
