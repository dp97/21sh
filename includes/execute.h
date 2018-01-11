#ifndef EXECUTE_H
# define EXECUTE_H
# define DONE			0
# define ERR			1
# define NOTHING_DONE	2
# define MATCH			3
# define NO_MATCH		4
# define EXIT			5
# include "libft.h"
# include "tokening.h"
# include <sys/wait.h>

int		ret_error(char *pmsg, char *msg, int code);
/*
**	execute.c	- Execute all commands in order.
*/
int		execute(char **cmds, char **env);
char	*search_in_path(char *name);
/*
**	builtin.c	- Run builtin programs.
*/
int		search_in_builtin(char *name, char **argv);
/*
**	ft_execve.c - Run programs from path.
*/
int		ft_execve(char *pathname, char **argv, char **env);
#endif
