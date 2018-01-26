#include "builtins.h"

int	builtin_cd(char **cmd, char **env)
{
	char	*operand;
	char	*curpath;
	char	*pwd;
	char	*home;

	curpath = NULL;
	operand = cmd[1];
	home = getenv("HOME");
	if ((pwd = getenv("PWD")) == NULL)
		return (ret_error("cd", "Failed to get 'PWD' env.", ERR));

	if (operand == NULL && home == NULL)
		return (DONE);
	if (operand == NULL && home)
		;//curpath = ft_strdup(home);
	if (operand[0] == '/')
		;
	if (operand[0] == '.' || ft_strncmp(operand, "..", 2) == 0)
		;
	curpath = pathcat(pwd, operand);//6
	if (chdir(curpath))//9
	{
		perror("ww");
		return (ret_error("chdir", curpath, ERR));
	}
	ft_setenv("OLDPWD", pwd, 1);
	ft_setenv("PWD", curpath, 1);
	ft_strdel(&curpath);
	return (DONE);
}
