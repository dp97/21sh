/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 12:33:31 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "input_stream.h"

char			*ft_readline(void)
{
	t_cmds		*history;
	t_cupos		cursor;
	char		*line;
	char		key[5];

	line = NULL;
	find();
	init_terminal_data();
	tty_enable_raw();
	history = ft_init_history();
	cursor.col_start = ft_strlen(PROMPT);
	cursor.col = cursor.col_start;
	cursor.col_end = cursor.col;
	tputs(tgetstr("ks", 0), 1, ft_puti);
	ft_strclr(key);
	while (read(STDIN_FILENO, &key, 5) && key[0] != '\r')
	{
//		printf("(%d-%d-%d-%d-%d)", key[0], key[1], key[2], key[3], key[4]);
	//printf("(%s)", key);
		if (ft_isprint(key[0]))
		{
			//printf("%d ('%c')\n", key, key);
		//	line = ft_strapnd(line, key);

			if (ft_strichar(&line, cursor.col - cursor.col_start, key[0]))
				printf("err");
//			 printf("<%s>", line);
			ft_insert(key, &cursor);
		}
		else
			detect_ctrl(key, &cursor, NULL, history);
		ft_strclr(key);
	}

	ft_update_history(line);
	free(line);
	ft_purgecmds(&history);
	tputs(tgetstr("ks", 0), 1, ft_puti);
	tty_disable_raw();
	return (NULL);
}
