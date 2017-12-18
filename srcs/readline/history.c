/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:51:28 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 19:33:55 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/*
**	Initiate history in s_chain struct in LIFO order.
**	ERR: NULL returned.
*/
t_chain		*ft_init_history(void)
{
	t_chain	*history;
	t_chain	*tmp;
	char	*line;
	int		fd;

	line = NULL;
	fd = open(HISTORY_PATH, O_RDONLY);
	if (fd < 0)
	{
		ft_log("Cannot initiate history, file not found.", 0);
		return (NULL);
	}
	history = NULL;
	while (get_next_line(fd, &line))
	{
		if ((tmp = ft_chainnew(NULL)) == NULL)
		{
			ft_strdel(&line);
			ft_log("Not enough memory.", 1);
			break ;
		}
		tmp->value = line;
		if (history)
			history->prev = tmp;
		tmp->next = history;
		history = tmp;
		line = NULL;
	}
	return (history);
}

void		ft_update_history(char *line)
{
	int		fd;

	if (line == NULL)
		return ;
	printf("{%s}", line);
	fd = open(HISTORY_PATH, O_WRONLY | O_APPEND | O_CREAT , S_IRUSR | S_IWUSR);
	if (fd < 0)
		ft_log("Failed to open 'HISTORY_PATH'", 1);
	ft_putstr_fd(line, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
}
