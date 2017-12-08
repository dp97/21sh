/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dota <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:19:49 by dpetrov           #+#    #+#             */
/*   Updated: 2016/11/25 15:38:59 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int		ft_set_null(int stat, char **s)
{
	if (stat == -2)
		*s = NULL;
	return (1);
}

static int		ft_read_buff(int fd, char **tab)
{
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			plus;

	if (!(plus = read(fd, buff, BUFF_SIZE)))
		return (0);
	else if (plus == -1)
		return (-1);
	buff[plus] = '\0';
	temp = ft_strjoin(*tab, buff);
	free(*tab);
	*tab = temp;
	return (1);
}

static int		ft_search_line(const int fd, char **data, char **word)
{
	int			status;

	if ((status = ft_read_buff(fd, &(*data))) == -1)
		return (-1);
	else if (status == 0)
	{
		if ((*word = ft_strchr(*data, '\0')) == *data)
			return (0);
	}
	else
		*word = ft_strchr(*data, '\n');
	if (status == 0)
		return (-2);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*rem[FD_SIZE];
	char		*word;
	int			status;

	if (fd < 0 || fd > FD_SIZE || !line)
		return (-1);
	if (!rem[fd] && ((rem[fd] = (char *)ft_memalloc(sizeof(char))) == NULL))
		return (-1);
	word = ft_strchr(rem[fd], '\n');
	while (word == NULL)
	{
		if ((status = ft_search_line(fd, &(rem[fd]), &word)) == -1)
			return (-1);
		else if (status == 0)
		{
			*line = NULL;
			return (0);
		}
	}
	if (!(*line = ft_strndup(rem[fd], word - rem[fd])))
		return (-1);
	word = ft_strdup(word + 1);
	free(rem[fd]);
	rem[fd] = word;
	return (ft_set_null(status, &(rem[fd])));
}
