/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_arrows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:52:25 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 18:14:31 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	move_cursor_one_word_left(t_cursor **cursor, char *line)
{
	int		pos;
	int		by;

	by = 0;
	pos = (*cursor)->col - (*cursor)->col_start - 1;
	while (pos >= 0 && line[pos] && !ft_isalpha(line[pos]))
	{
		pos--;
		(*cursor)->col--;
		by++;
	}
	while (pos >= 0 && line[pos] && ft_isalpha(line[pos]))
	{
		pos--;
		(*cursor)->col--;
		by++;
	}
	if (by)
		tputs(tgoto(tgetstr("LE", 0), 0, by), 1, ft_puti);
	return (1);
}

static int	move_cursor_one_word_right(t_cursor **cursor, char *line)
{
	int		pos;
	int		by;
	
	by = 0;
	pos = (*cursor)->col - (*cursor)->col_start;
	while (pos >= 0 && line[pos] && !ft_isalpha(line[pos]))
	{
		pos++;
		(*cursor)->col++;
		by++;
	}
	while (pos >= 0 && line[pos] && ft_isalpha(line[pos]))
	{
		pos++;
		(*cursor)->col++;
		by++;
	}
	if (by)
		tputs(tgoto(tgetstr("RI", 0), 0, by), 1, ft_puti);
	return (1);
}

static int	move_cursor_one_line_up(t_cursor **cursor)
{
	if ((*cursor)->prev)
	{
		tputs(tgetstr("up", 0), 2, ft_puti);
		*cursor = (*cursor)->prev;
		(*cursor)->col = (*cursor)->next->col;
		if ((*cursor)->col > (*cursor)->col_end)
		{
			(*cursor)->col = (*cursor)->col_end;
			tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_end), 1, ft_puti);
		}
		else if ((*cursor)->col < (*cursor)->col_start)
		{
			(*cursor)->col = (*cursor)->col_start;
			tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_start), 1, ft_puti);
		}
		return (1);
	}
	return (-1);
}

static int	move_cursor_one_line_down(t_cursor **cursor)
{
	if ((*cursor)->next)
	{
		tputs(tgetstr("do", 0), 1, ft_puti);
		*cursor = (*cursor)->next;
		(*cursor)->col = (*cursor)->prev->col;
		if ((*cursor)->col > (*cursor)->col_end)
		{
			(*cursor)->col = (*cursor)->col_end;
			tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_end), 1, ft_puti);
		}
		else if ((*cursor)->col < (*cursor)->col_start)
		{
			(*cursor)->col = (*cursor)->col_start;
			tputs(tgoto(tgetstr("ch", 0), 0, (*cursor)->col_start), 1, ft_puti);
		}
		return (1);
	}
	return (-1);
}

int			if_shift_keypad(char *key, t_cursor **cursor, t_cmds **history)
{
	char	*line;
	int		ret;

	ret = 0;
	line = ft_strndup(&(*history)->value[calc_pos_relative(*cursor, (*cursor)->col_start)], \
						(*cursor)->col_end - (*cursor)->col_start);
	if (ft_strequ("\e[1;2D", key))
		ret = move_cursor_one_word_left(cursor, line);
	else if (ft_strequ("\e[1;2C", key))
		ret = move_cursor_one_word_right(cursor, line);
	else if (ft_strequ("\e[1;2A", key))
		ret = move_cursor_one_line_up(cursor);
	else if (ft_strequ("\e[1;2B", key))
		ret = move_cursor_one_line_down(cursor);
	ft_strdel(&line);
	return (ret);
}
