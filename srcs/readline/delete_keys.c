#include "ft_readline.h"

int		backspace_char(char **line, t_cursor *cursor)
{
	int	pos;

	pos = (*cursor).col - (*cursor).col_start - 1;
	if (line && arrows(ARROW_LEFT, cursor, NULL, NULL) == RET_OK)
	{
		if (ft_strdchar(line, pos))
			return (ERR);
		tputs(DELETE_CHAR, 1, ft_puti);
		(*cursor).col_end--;
		return (DONE);
	}
	return (NOTHING_DONE);
}

int		delete_char(char **line, t_cursor *cursor)
{
	int	pos;

	pos = (*cursor).col - (*cursor).col_start;
	if (line && (*cursor).col < (*cursor).col_end)
	{
		if (ft_strdchar(line, pos))
			return (ERR);
		tputs(DELETE_CHAR, 1, ft_puti);
		(*cursor).col_end--;
		return (DONE);
	}
	return (NOTHING_DONE);
}

int		delete_keys(char *ctrl, char **l, t_cursor *cursor)
{
	if (ft_strcmp(ctrl, BACKSPACE_KEY) == 0 || ft_strcmp(ctrl, BACKSPACE) == 0)
		backspace_char(l, cursor);
	else if (ft_strcmp(ctrl, CTRL_D_KEY) == 0)
	{
		if (*l == NULL)
			return (EXIT);
		else
			delete_char(l, cursor);
	}
	else if (ft_strcmp(ctrl, DELETE_KEY) == 0)
		delete_char(l, cursor);
	else
		return (NO_MATCH);
	return (MATCH);
}
