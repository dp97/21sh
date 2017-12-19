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

static int	move_cursor_left(t_cursor *cursor, t_chain **line)
{
	if ((*cursor).col_start < (*cursor).col)
	{
		tputs(tgetstr("le", 0), 1, ft_puti);
		(*cursor).col--;
		return (RET_OK);
	}
	return (RET_MIRR);
}

static int	move_cursor_right(t_cursor *cursor, t_chain **line)
{
	if ((*cursor).col < (*cursor).col_end)
	{
		tputs(tgetstr("nd", 0), 1, ft_puti);
		(*cursor).col++;
		return (RET_OK);
	}
	return (RET_MIRR);
}

static int	ft_history_up(t_cursor *cursor, t_chain **line, t_chain **history)
{
	if (*history)
	{
		(*history)->value = (*line)->value;
		if ((*history)->next == NULL)
			return (NOTHING_DONE);
		*history = (*history)->next;
		ft_replace_line((*history)->value, cursor);
		(*line)->value = (*history)->value;
		return (DONE);
	}
	return (NOTHING_DONE);
}

static int	ft_history_do(t_cursor *cursor, t_chain **line, t_chain **history)
{
	if (*history)
	{
		(*history)->value = (*line)->value;
		if ((*history)->prev == NULL)
			return (NOTHING_DONE);
		*history = (*history)->prev;
		ft_replace_line((*history)->value, cursor);
		(*line)->value = (*history)->value;
		return (DONE);
	}
	return (NOTHING_DONE);
}

int			arrows(char *ctrl, t_cursor *cursor, t_chain **line, t_chain **history)
{
	if (ft_strcmp(ARROW_UP, ctrl) == 0)
		ft_history_up(cursor, line, history);
	else if (ft_strcmp(ARROW_DOWN, ctrl) == 0)
		ft_history_do(cursor, line, history);
	else if (ft_strcmp(ARROW_RIGHT, ctrl) == 0)
		move_cursor_right(cursor, line);
	else if (ft_strcmp(ARROW_LEFT, ctrl) == 0)
		move_cursor_left(cursor, line);
	else
		return (RET_MIRR);
	return (RET_OK);
}
