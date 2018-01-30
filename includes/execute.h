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
# include "parser.h"
# include <sys/wait.h>

int		ret_error(char *pmsg, char *msg, int code);
/*
**	execute.c	- Entry Point.
*/
int		execute(t_cmd *cmds, char **env);
int		execute_cmd(char **cmds, char **env);
int   piping(char **first_cmd, char **second_cmd, char **env);
/*
**  path.c  - Search command location in system.
*/
char	*search_in_path(char *name);
/*
**	builtin.c	- Run builtin programs.
*/
int		search_in_builtin(char *name, char **argv, char **env);
/*
**	ft_execve.c - Run programs from path.
*/
int		ft_execve(char *pathname, char **argv, char **env);
#endif
