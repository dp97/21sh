
#include "ft_readline.h"

static void	move_cursor_one_word_left(t_cursor *cursor, char *line)
{
	int		pos;
	int		by;

	by = 0;
	pos = (*cursor).col - (*cursor).col_start - 1;
	while (pos >= 0 && line[pos] && !ft_isalpha(line[pos]))
	{
		pos--;
		(*cursor).col--;
		by++;
	}
	while (pos >= 0 && line[pos] && ft_isalpha(line[pos]))
	{
		pos--;
		(*cursor).col--;
		by++;
	}
	if (by)
		tputs(tgoto(tgetstr("LE", 0), 0, by), 1, ft_puti);
}

static void	move_cursor_one_word_right(t_cursor *cursor, char *line)
{
	int		pos;
	int		by;
	
	by = 0;
	pos = (*cursor).col - (*cursor).col_start;
	while (pos >= 0 && line[pos] && !ft_isalpha(line[pos]))
	{
		pos++;
		(*cursor).col++;
		by++;
	}
	while (pos >= 0 && line[pos] && ft_isalpha(line[pos]))
	{
		pos++;
		(*cursor).col++;
		by++;
	}
	if (by)
		tputs(tgoto(tgetstr("RI", 0), 0, by), 1, ft_puti);
}

static int	move_cursor_one_line_up(t_cursor *cursor)
{
}

static int	move_cursor_one_line_down(t_cursor *cursor)
{
}

int			shift_plus_arrows(char *ctrl, t_cursor *cursor, t_chain **line)
{
	if (ft_strcmp(SHIFT_LEFT, ctrl) == 0)
		move_cursor_one_word_left(cursor, (*line)->value);
	else if (ft_strcmp(SHIFT_RIGHT, ctrl) == 0)
		move_cursor_one_word_right(cursor, (*line)->value);
	else if (ft_strcmp(SHIFT_UP, ctrl) == 0)
		move_cursor_one_line_up(cursor);
	else if (ft_strcmp(SHIFT_DOWN, ctrl) == 0)
		move_cursor_one_line_down(cursor);
	else
		return (NOTHING_DONE);
	return (DONE);
}
