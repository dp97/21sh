#include "execute.h"

int	search_in_builtin(char *name, char **argv)
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