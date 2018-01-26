
#ifndef BUILTINS_H
# define BUILTINS_H
# include "libft.h"
# include "minishell.h"

int	builtin_cd(char **cmd, char **env);
int	ft_setenv(char *name, char *val, int overwrite);
#endif
