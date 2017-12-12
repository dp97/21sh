#include "ft_readline.h"

static void	move_cursor_begin_line(t_cursor **cursor)
{
	if ((*cursor)->col != (*cursor)->col_start)
	{
		tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_start), 1, ft_puti);
		(*cursor)->col = (*cursor)->col_start;
	}
}

static void	move_cursor_end_line(t_cursor **cursor)
{
	if ((*cursor)->col != (*cursor)->col_end)
	{
		tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_end), 1, ft_puti);
		(*cursor)->col = (*cursor)->col_end;
	}
}

int			if_msc_keypad(char *key, t_cursor **cursor)
{
	if (ft_strequ(tgetstr("kh", 0), key))
		move_cursor_begin_line(cursor);
	else if (ft_strequ(tgetstr("@7", 0), key))
		move_cursor_end_line(cursor);
	else
		return (0);
	return (1);
}
