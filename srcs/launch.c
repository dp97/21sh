/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:39:22 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/04 12:42:00 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		parrent_process(pid_t pid)
{
	int		status;

	while (1)
	{
		waitpid(pid, &status, WUNTRACED);
		if (!WIFEXITED(status) || !WIFSIGNALED(status))
		{
			if (WTERMSIG(status) == SIGINT)
				g_sig = 2;
			break ;
		}
	}
}

static void	absolute_path(char **args, char **env)
{
	if (execve(args[0], args, env) == -1)
	{
		if (access(args[0], X_OK))
			check_error(args[0], ": permission denied.");
		else
			check_error(args[0], ": Command not found.");
	}
	exit(1);
}

void		child_process(char **args, char **env, char *path)
{
	char	full[256];
	int		lp;
	int		ln;

	if (args[0][0] == '/' || args[0][0] == '.')
		absolute_path(args, env);
	lp = ft_strlen(args[0]);
	while (path && (path = ft_strchr(path, '/')))
	{
		ln = 0;
		while (path[ln] && path[ln] != ':')
			++ln;
		ft_memcpy(full, path, ln);
		path += ln;
		full[ln++] = '/';
		ft_memcpy(full + ln, args[0], lp + 1);
		if (execve(full, args, env) == -1)
			continue;
	}
	check_error(args[0], ": Command not found.");
	exit(1);
}

int			ft_launch(char **args, char **env)
{
	pid_t	pid;
	char	*home;

	home = ft_getenv("PATH", env);
	pid = fork();
	if (pid == 0)
		child_process(args, env, home);
	else if (pid < 0)
	{
		ft_putendl_fd("fork: Could not fork processes.", STDERR_FILENO);
		exit(1);
	}
	else
		parrent_process(pid);
	return (0);
}
