/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:00:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 18:02:09 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int	move_cursor_left(t_cursor **cursor)
{
	if ((*cursor)->col_start < (*cursor)->col)
	{
		tputs(tgetstr("le", 0), 1, ft_puti);
		(*cursor)->col--;
		return (1);
	}
	return (0);
}

static int	move_cursor_right(t_cursor **cursor)
{
	if ((*cursor)->col < (*cursor)->col_end)
	{
		if (tgetstr("nd", 0) == NULL)
			ft_log("no wayyy", 1);
		tputs(tgetstr("nd", 0), 1, ft_puti);
		(*cursor)->col++;
		return (1);
	}
	return (0);
}

static void	change_input(t_cursor **cursor, char *line)
{
	while (move_cursor_right(cursor))
		;
	while (del_char(cursor, 1, NULL))
		;
	ft_insert(line, cursor);
}

static void	ft_history(t_cursor **cursor, t_cmds **history, short up)
{
	if (up)
	{
		if ((*history)->next == NULL)
			return ;
		*history = (*history)->next;
		change_input(cursor, (*history)->value);
	}
	else
	{
		if ((*history)->prev == NULL)
			return ;
		*history = (*history)->prev;
		change_input(cursor, (*history)->value);
	}
}

int			if_keypad(char *ctrl, t_cursor **cursor, t_cmds **history)
{
	if (ft_strcmp(tgetstr("ku", 0), ctrl) == 0)
		ft_history(cursor, history, 1);
	else if (ft_strcmp(tgetstr("kd", 0), ctrl) == 0)
		ft_history(cursor, history, 0);
	else if (ft_strcmp(tgetstr("kr", 0), ctrl) == 0)
		move_cursor_right(cursor);
	else if (ft_strcmp(tgetstr("kl", 0), ctrl) == 0)
		move_cursor_left(cursor);
	else
		return (0);
	return (1);
}
