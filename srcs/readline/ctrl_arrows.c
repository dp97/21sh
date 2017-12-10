#include "ft_readline.h"

static void	move_cursor_one_word_left(t_cupos *cursor, char *line)
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

static void	move_cursor_one_word_right(t_cupos *cursor, char *line)
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

int		if_ctrl_keypad(char *key, t_cupos *cursor, t_cmds **history)
{
	if (ft_strequ("\e[1;5D", key))
		move_cursor_one_word_left(cursor, (*history)->value);
	else if (ft_strequ("\e[1;5C", key))
		move_cursor_one_word_right(cursor, (*history)->value);
	else
		return (0);
	return (1);
}
