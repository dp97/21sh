
#include "ft_readline.h"

static int	move_cursor_one_word_left(t_cursor *cursor, char *line)
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
	return (1);
}

static int	move_cursor_one_word_right(t_cursor *cursor, char *line)
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
	return (1);
}

static int	move_cursor_one_line_up(t_cursor *cursor)
{
}

static int	move_cursor_one_line_down(t_cursor *cursor)
{
}

int			shift_plus_arrows(char *ctrl, t_cursor *cursor, t_chain **line)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(SHIFT_LEFT, ctrl))
		ret = move_cursor_one_word_left(cursor, NULL);
	else if (ft_strequ(SHIFT_RIGHT, ctrl))
		ret = move_cursor_one_word_right(cursor, NULL);
	else if (ft_strequ(SHIFT_UP, ctrl))
		ret = move_cursor_one_line_up(cursor);
	else if (ft_strequ(SHIFT_DOWN, ctrl))
		ret = move_cursor_one_line_down(cursor);
	return (ret);
}
