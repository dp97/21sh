/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:00:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 19:28:01 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			move_cursor_left(t_cursor **cursor, t_cmds **history)
{
	if ((*cursor)->col_start < (*cursor)->col)
	{
		tputs(tgetstr("le", 0), 1, ft_puti);
		(*cursor)->col--;
		return (RET_OK);
	}
	else if (history && (*cursor)->col == (*cursor)->col_start && (*cursor)->prev)
	{
		if (if_shift_keypad("\e[1;2A", cursor, history) == 1)
		{
			if_msc_keypad(tgetstr("@7", 0), cursor);
			return (RET_OK);
		}
	}
	return (RET_MIRR);
}

static int	move_cursor_right(t_cursor **cursor, t_cmds **history)
{
	if ((*cursor)->col < (*cursor)->col_end)
	{
		if (tgetstr("nd", 0) == NULL)
			ft_log("no wayyy", 1);
		tputs(tgetstr("nd", 0), 1, ft_puti);
		(*cursor)->col++;
		return (RET_OK);
	}
	else if (history && (*cursor)->col == (*cursor)->col_end && (*cursor)->next)
	{
		if (if_shift_keypad("\e[1;2B", cursor, history) == 1)
		{
			if_msc_keypad(tgetstr("kh", 0), cursor);
			return (RET_OK);
		}
	}
	return (RET_MIRR);
}

static int	change_input(t_cursor **cursor, char **line, char *input)
{
	char	*tmp;

	tmp = input;
	while (move_cursor_right(cursor, NULL))
		;
	while (del_char(cursor, 1, NULL))
		;
	while (*tmp)
	{
		if (print(line, cursor, *tmp) == RET_ERR)
			return (RET_ERR);
		tmp++;
	}
	return (RET_OK);
}

static int	ft_history(t_cursor **cursor, t_cmds **history, short up)
{
	char	*input;

	if (up)
	{
		if ((input = ft_cmdgetnextvalue(*history)) == NULL)
			return (RET_MIRR);
		return (change_input(cursor, &((*history)->value), input));
	}
	else
	{
		if ((input = ft_cmdgetprevvalue(*history)) == NULL)
			return (RET_MIRR);
		return (change_input(cursor, &((*history)->value), input));
	}
}

int			if_keypad(char *ctrl, t_cursor **cursor, t_cmds **history)
{
	if (ft_strcmp(tgetstr("ku", 0), ctrl) == 0)
		ft_history(cursor, history, 1);
	else if (ft_strcmp(tgetstr("kd", 0), ctrl) == 0)
		ft_history(cursor, history, 0);
	else if (ft_strcmp(tgetstr("kr", 0), ctrl) == 0)
		move_cursor_right(cursor, history);
	else if (ft_strcmp(tgetstr("kl", 0), ctrl) == 0)
		move_cursor_left(cursor, history);
	else
		return (RET_MIRR);
	return (1);
}
