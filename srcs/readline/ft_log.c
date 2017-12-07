/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:20:17 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 18:00:48 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/*
**	Logs the errors in file pointed by LOG_PATH macro.
*/
void	ft_log(char *msg, short critical)
{
	int			fd;
	
	fd = open(LOG_PATH, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd < 0)
		return ;
	if (critical)
		write(fd, "CRITICAL!!! -->", 15);
	write(fd, msg, ft_strlen(msg));
	write(fd, "\n", 1);
	close(fd);
}
