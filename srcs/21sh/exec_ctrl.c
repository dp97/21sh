/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:31:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 18:29:44 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			ft_puti(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

static void	ft_mode(char *req)
{
	char	*code;

	code = tgetstr(req, 0);
	if (code == NULL)
	{
		ft_mode("me");
		ft_putstr_fd("not mode", STDIN_FILENO);
	}
	tputs(code, 1, ft_puti);
}

/*
**	Delete a char from input stream.
**	If 'which' is 1 then left char from cursor is deleted,
**	else the char at cursor position is deleted.
*/
void	del_char(t_cupos *cursor, short which)
{
	if (which && move_cursor_left(cursor))
	{
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor).col_end--;
	}
	else if (which == 0 && (*cursor).col < (*cursor).col_end)
	{
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor).col_end--;
	}
}

void	ft_insert(char key)
{
	ft_mode("im");
	write(STDIN_FILENO, &key, 1);
	tputs(tgetstr("ei", 0), 1, ft_puti);
}
