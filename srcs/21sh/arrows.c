/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:00:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 18:09:45 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int	move_cursor_left(t_cupos *cursor)
{
	if ((*cursor).col_start < (*cursor).col)
	{
		tputs(tgetstr("le", 0), 1, ft_puti);
		(*cursor).col--;
		return (1);
	}
	return (0);
}

static int	move_cursor_right(t_cupos *cursor)
{
	if ((*cursor).col < (*cursor).col_end)
	{
		tputs(tgetstr("nd", 0), 1, ft_puti);
		(*cursor).col++;
		return (1);
	}
	return (0);
}

int	if_keypad(char *ctrl, t_cupos *cursor)
{
	if (ft_strcmp(tgetstr("ku", 0), ctrl) == 0)
		tputs(tgetstr("up", 0), 1, ft_puti);/*history*/
	else if (ft_strcmp(tgetstr("kd", 0), ctrl) == 0)
		tputs(tgetstr("do", 0), 1, ft_puti);/*history*/
	else if (ft_strcmp(tgetstr("kr", 0), ctrl) == 0)
		move_cursor_right(cursor);
	else if (ft_strcmp(tgetstr("kl", 0), ctrl) == 0)
		move_cursor_left(cursor);
	else
		return (0);
	return (1);
}
