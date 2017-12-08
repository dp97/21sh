/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:31:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 09:09:44 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

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
int		del_char(t_cupos *cursor, short which, t_cmds **head)
{
	int	position;

	(void)head;
	position = (*cursor).col - (*cursor).col_start;
	if (which && move_cursor_left(cursor))
	{
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor).col_end--;
		return (1);
	}
	else if (which == 0 && (*cursor).col < (*cursor).col_end)
	{
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor).col_end--;
		return (1);
	}
	return (0);
}

void	ft_insert(char *line, t_cupos *cursor)
{
	int	len;

	len = ft_strlen(line);
	ft_mode("im");
	write(STDIN_FILENO, line, len);
	tputs(tgetstr("ei", 0), 1, ft_puti);
	(*cursor).col += len;
	(*cursor).col_end += len;
}
