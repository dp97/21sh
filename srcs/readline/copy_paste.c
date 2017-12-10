#include "ft_readline.h"

static char	*copycut_tillcursor(t_cupos *cursor, t_cmds **history)
{
	char	*copy;

	copy = ft_strndup((*history)->value, (*cursor).col - (*cursor).col_start);
	while (del_char(cursor, 1, &((*history)->value)))
		;
	return (copy);
}

static void	ft_paste(char *line, t_cupos *cursor, t_cmds **history)
{
	if (line)
		print(history, cursor, line);
}

int			if_copy_paste(char *key, t_cupos *cursor, t_cmds **history, char **in_memory)
{
	if (ft_strcmp("\x015", key) == 0)
		*in_memory = copycut_tillcursor(cursor, history);
	else if (ft_strcmp("\x019", key) == 0)
		ft_paste(*in_memory, cursor, history);
	else
		return (0);
	return (1);
}
