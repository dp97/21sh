/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:03:01 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/02 13:06:00 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*my_read_line(void)
{
	char	*line;

	line = NULL;
	if ((get_next_line(1, &line)) < 0)
		ft_error("error geting line Sir !");
	return (line);
}

void		sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\b\b\x07F\x07F\b\b", 6);
		write(1, "\n$> ", 4);
	}
}

void		set_null_id(t_cmd *history)
{
	int		position;

	position = 0;
	while (position < FIFO_SIZE)
	{
		history[position].id = 0;
		++position;
	}
}

void		capture_time(char *buf)
{
	time_t	tme;
	char	*date;

	tme = time(NULL);
	date = ctime(&tme);
	ft_strncpy(buf, &date[11], 5);
	buf[5] = '\0';
}
