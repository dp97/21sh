/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:22:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 18:21:55 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	detect_ctrl(char *ctrl, t_cursor **cursor, t_cmds **history)
{
	if (ctrl[0] == 127)
		del_char(cursor, 1, history);
	else if (ctrl[0] == 3)
		ft_putstrstr("\n\r", PROMPT);
	else if (ctrl[0] == 4)
		del_char(cursor, 0, history);
	else if (ctrl[0] == 6)
	{
		char c;
		read(STDOUT_FILENO, &c, 1);
		printf("<%d>", c);
	}
	else if (ctrl[0] == 5)
	{
		tty_disable_raw();
		exit(EXIT_SUCCESS);
	}
	else if (if_keypad(ctrl, cursor, history))
		return ;
	else if (if_shift_keypad(ctrl, cursor, history))
		return ;
	else if (if_msc_keypad(ctrl, cursor))
		return ;

	//char *key = tgetstr("kl", 0);
	//printf("/%d-%c-%c-%c-%c-%c/", ctrl[0], ctrl[1], ctrl[2], ctrl[3], ctrl[4], ctrl[5]);
}
