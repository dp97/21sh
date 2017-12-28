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
typedef struct s_token t_cmd;

int	execute(t_cmd *cmds, char **env);
int	search_in_path(char *name);
#endif
