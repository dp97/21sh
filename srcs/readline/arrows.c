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
		if (tgetstr("nd", 0) == NULL)
			ft_log("no wayyy", 1);
		tputs(tgetstr("nd", 0), 1, ft_puti);
		(*cursor).col++;
		return (RET_OK);
	}
	return (RET_MIRR);
}

static int	change_input(t_cursor **cursor, char **line, char *input)
{
}

static int	ft_history(t_cursor *cursor, t_chain **line, short up)
{
}

int			arrows(char *ctrl, t_cursor *cursor, t_chain **line)
{
	if (ft_strcmp(ARROW_UP, ctrl) == 0)
		ft_history(cursor, line, 1);
	else if (ft_strcmp(ARROW_DOWN, ctrl) == 0)
		ft_history(cursor, line, 0);
	else if (ft_strcmp(ARROW_RIGHT, ctrl) == 0)
		move_cursor_right(cursor, line);
	else if (ft_strcmp(ARROW_LEFT, ctrl) == 0)
		move_cursor_left(cursor, line);
	else
		return (RET_MIRR);
	return (RET_OK);
}
