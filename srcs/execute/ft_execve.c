#include "execute.h"

int			ft_execve(char *pathname, char **argv, char **env)
{
	pid_t	pid;
	int		status;
	
	if (access(pathname, X_OK))
		return (ret_error(pathname, "Permission denied.", 1));

	pid = fork();
	if (pid == -1)
		return (ret_error("fork", "Failed to initiate a child process.", ERR));

	if (pid)//parent
	{
		while (1)
		{
			if (waitpid(pid, &status, 0) == -1)
				return (ret_error("waitpid", "Interupted by a signal.", ERR));

			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				return (WTERMSIG(status));
			else if (WIFSTOPPED(status))
				return (WSTOPSIG(status));
			else
				return (status);
		}
	}
	else//child;
	{
		execve(pathname, argv, env);
		return (ret_error("execve", "Failed.", ERR));
	}
	return (DONE);
}
