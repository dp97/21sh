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
typedef struct s_token t_cmd;

int		ret_error(char *pmsg, char *msg, int code);
int		execute(t_cmd *cmds, char **env);
char	*search_in_path(char *name);
int		ret_error(char *pmsg, char *msg, int code);
#endif
