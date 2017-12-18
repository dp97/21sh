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

void	detect_ctrl(char *ctrl, t_cursor **cursor, t_chain **line)
{
	if (strcmp(ctrl, "\x7F") == 0)
		del_char(cursor, 1, &((*line)->value));
	else if (ctrl[0] == 3)
		ft_putstrstr("\n\r", PROMPT);
	else if (ctrl[0] == 4)
		del_char(cursor, 0, &((*line)->value));
	else if (ctrl[0] == 5)
	{
		tty_disable_raw();
		exit(EXIT_SUCCESS);
	}
	else if (arrows(ctrl, cursor, line) == RET_OK)
		return ;
	else if (shift_plus_arrows(ctrl, cursor, line))
		return ;
	else if (if_msc_keypad(ctrl, cursor))
		return ;

	//char *key = tgetstr("kl", 0);
	//printf("/%d-%c-%c-%c-%c-%c/", ctrl[0], ctrl[1], ctrl[2], ctrl[3], ctrl[4], ctrl[5]);
}
