/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:22:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:46:08 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	detect_ctrl(char *ctrl, t_cupos *cursor, t_cmds **history)
{
//	printf("{%c}", ctrl);
	if (ctrl[0] == 127)
		del_char(cursor, 1, &((*history)->value));
	else if (ctrl[0] == 3)
		ft_putstrstr("\n\r", PROMPT);
	else if (ctrl[0] == 4)
		del_char(cursor, 0, &((*history)->value));
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
	if_keypad(ctrl, cursor, history);

	//char *key = tgetstr("kl", 0);
	//printf("/%d-%d-%d-%d-%d/", key[0], key[1], key[2], key[3], key[4]);
}
