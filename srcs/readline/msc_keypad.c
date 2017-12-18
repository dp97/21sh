#include "ft_readline.h"

static void	move_cursor_begin_line(t_cursor *cursor)
{
	if ((*cursor).col != (*cursor).col_start)
	{
		tputs(tgoto(CH_CURSOR_COL, 0, (*cursor).col_start), 1, ft_puti);
		(*cursor).col = (*cursor).col_start;
	}
}

static void	move_cursor_end_line(t_cursor *cursor)
{
	if ((*cursor).col != (*cursor).col_end)
	{
		tputs(tgoto(CH_CURSOR_COL, 0, (*cursor).col_end), 1, ft_puti);
		(*cursor).col = (*cursor).col_end;
	}
}

int			if_msc_keypad(char *key, t_cursor *cursor)
{
	if (ft_strcmp(HOME_KEY, key) == 0)
		move_cursor_begin_line(cursor);
	else if (ft_strcmp(END_KEY, key) == 0)
		move_cursor_end_line(cursor);
	else
		return (NOTHING_DONE);
	return (DONE);
}
