/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 19:33:12 by dpetrov          ###   ########.fr       */
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
	history = ft_init_history();
	cursor.col_start = ft_strlen(PROMPT);
	cursor.col = cursor.col_start;
	cursor.col_end = cursor.col;
	tputs(tgetstr("ks", 0), 1, ft_puti);
	ft_bzero(key, 5);
	while (read(STDIN_FILENO, &key, 5) && key[0] != '\r')
	{
//		printf("(%d-%d-%d-%d-%d)", key[0], key[1], key[2], key[3], key[4]);
	//printf("(%s)", key);
		if (ft_isprint(key[0]))
		{
			//printf("%d ('%c')\n", key, key);
		//	line = ft_strapnd(line, key);
			ft_insert(key, &cursor);
		}
		else
			detect_ctrl(key, &cursor, NULL, history);
		ft_bzero(key, 5);
	}

	ft_update_history(line);
	free(line);
	ft_purgecont(&history);
	tputs(tgetstr("ks", 0), 1, ft_puti);
	return (NULL);
}
