/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:55:28 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "input_stream.h"

char			*ft_readline(void)
{
	t_cmds		*history;
	t_cupos		cursor;
	char		key[9];

	history = ft_init_history();

	if (ft_cmdprepend(&history, ft_cmdnew(NULL)))
	{
		ft_log("Failed to initiate 'line'.", 1);
		return (NULL);
	}

//	find();
	init_terminal_data();
	tty_enable_raw();

	cursor.col_start = ft_strlen(PROMPT);
	cursor.col = cursor.col_start;
	cursor.col_end = cursor.col;

	tputs(tgetstr("ks", 0), 1, ft_puti);
	ft_bzero(key, 9);
	ft_putstrstr("\n\r", PROMPT);
	while (read(STDIN_FILENO, &key, 9) && key[0] != '\r')
	{
//		printf("(%d-%d-%d-%d-%d-%d)", key[0], key[1], key[2], key[3], key[4], key[5]);
		if (ft_isprint(key[0]))
		{
			//printf("%d ('%c')\n", key, key);

			if (ft_strichar(&history->value, cursor.col - cursor.col_start, key[0]))
				ft_log("Insuficient memory for inserting a character.", 1);
			ft_insert(key, &cursor);
		}
		else
		{detect_ctrl(key, &cursor, &history);}
		ft_strclr(key);
	}
ft_putstrstr("\n\r", history->value);
	if (history->value)
		ft_update_history(history->value);
	ft_purgecmds(&history);

	tputs(tgetstr("ke", 0), 1, ft_puti);
	tty_disable_raw();
	return (NULL);
}
