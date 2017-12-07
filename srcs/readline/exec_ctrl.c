/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:31:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 19:42:23 by dpetrov          ###   ########.fr       */
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
int		del_char(t_cupos *cursor, short which, t_chcont **head)
{
	int	position;

	position = (*cursor).col - (*cursor).col_start;
	if (which && move_cursor_left(cursor))
	{
		ft_delcont(head, position - 1);
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor).col_end--;
		return (1);
	}
	else if (which == 0 && (*cursor).col < (*cursor).col_end)
	{
		ft_delcont(head, position);
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
	write(STDIN_FILENO, len, len);
	tputs(tgetstr("ei", 0), 1, ft_puti);
	(*cursor).col += len;
	(*cursor).col_end += len;
}
