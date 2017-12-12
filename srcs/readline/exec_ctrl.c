/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:31:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 19:15:05 by dpetrov          ###   ########.fr       */
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
int		del_char(t_cursor **cursor, short which, t_cmds **history)
{
	char	**line;
	int	position;

	line = history ? &((*history)->value) : NULL;
	position = (*cursor)->col - (*cursor)->col_start;
	if (which && move_cursor_left(cursor, NULL))
	{
		if (line)
			if (ft_strdchar(line, position - 1))
				return (0);
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor)->col_end--;
		return (1);
	}
	else if (which == 0 && (*cursor)->col < (*cursor)->col_end)
	{
		if (line)
			if (ft_strdchar(line, position))
				return (0);
		tputs(tgetstr("dc", 0), 1, ft_puti);
		(*cursor)->col_end--;
		return (1);
	}
	return (0);
}

/*	Enable insert mode and insert string by characters then disable the mode */
void	ft_insert(char input, t_cursor **cursor)
{
	ft_mode("im");
	ft_putchar_fd(input, STDIN_FILENO);
	ft_mode("ei");
	(*cursor)->col++;
	(*cursor)->col_end++;
}
