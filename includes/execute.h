#ifndef EXECUTE_H
# define EXECUTE_H
# define INVALID_FD     -1
# define DONE			0
# define ERR			1
# define NOTHING_DONE	2
# define MATCH			3
# define NO_MATCH		4
# define EXIT			5
# include "libft.h"
# include "tokening.h"
# include "parser.h"
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

int		ret_error(char *pmsg, char *msg, int code);
/*
**	execute.c	- Entry Point.
*/
int		execute(t_cmd *cmds, char **env);
int		search_and_run(char **cmds, char **env);
int   piping(char **cmd, char **env);
int get_input_from(t_scmd *scmd, char **env);
int open_streams(t_scmd *sc);

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
