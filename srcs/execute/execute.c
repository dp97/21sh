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

static int	search_in_builtin(char *name, char **argv)
{
	int		ret;

	if (ft_strcmp(name, "exit") == 0)
		return (EXIT);
	/*else if (ft_strcmp(args[0], "cd") == 0)
		ret = ft_cd(args, env);
	else if (ft_strcmp(args[0], "echo") == 0)
		ret = ft_echo(&args);
	else if (ft_strcmp(args[0], "env") == 0)
		ret = ft_env(args, env);
	else if (ft_strcmp(args[0], "setenv") == 0)
		ret = ft_setenv(args, env);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		ret = ft_unsetenv(args, env);
	else if (ft_strcmp(args[0], "printenv") == 0)
		ret = ft_printenv(args, env);
	else if (ft_strcmp(args[0], "history") == 0)
		ret = 0;//ft_history(&history);
	else if (ft_strcmp(args[0], ":") == 0)
		return (1);*/
	return (NO_MATCH);
}

char	**get_arguments_vector(t_cmd *cmd)
{
	t_cmd	*tmp;
	char	**argv;
	int		len;

	len = 0;
	tmp = cmd;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if ((argv = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	len = 0;
	tmp = cmd;
	while (tmp)
	{
		argv[len++] = tmp->value;
		tmp = tmp->next;
	}
	argv[len] = NULL;
	return (argv);
}

static int	ft_execve(char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		status;
	
	if (access(pathname, X_OK))
		return (ret_error(pathname, "Permission denied.", 1));

	pid = fork();
	if (pid == -1)
		return (ret_error("fork", "Failed to initiate a child process.", ERR));

	if (pid == 0)//parent
	{
		while (1)
		{
			wait(&status);
			if (WIFEXITED(status))
				break ;
		}
	}
	else//child;
	{
		execve(pathname, argv, env);
		return (ret_error("execve", "Failed.", ERR));
	}
	return (DONE);
}

/*
**	Execute commands according tp POSSIX 1003.1 standart.
*/
int			execute(t_cmd *cmds, char **env)
{
	t_cmd	*cmd;
	char	**argv;
	char	*exec;
	int		ret_code;

	ret_code = 0;
	cmd = cmds;
	argv = get_arguments_vector(cmd);
	if (ft_strchr(cmd->value, '/') == NULL)
	{
		if ((ret_code = search_in_builtin(cmd->value, argv)) != NO_MATCH)
			free(argv);
		else if (0)
			;// case b
		else if (0)
			;// case c
		else
		{
			if ((exec = search_in_path(cmd->value)) != NULL)
				ret_code = ft_execve(exec, argv, env);
			else
				return (ret_error(cmd->value, "Command not found.", 127));
		}
	}
	else
		;
	return (ret_code);
}
