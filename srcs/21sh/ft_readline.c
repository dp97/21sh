/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 14:34:55 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

char		*ft_readline(void)
{
	char	*line;
	char	key[5];

	/*line = NULL;
	if ((get_next_line(STDIN_FILENO, &line)) < 0)
		ft_error("error geting line Sir !");
		ft_putstr_fd(line, STDIN_FILENO);*/
	line = NULL;
	tputs(tgetstr("ks", 0), 1, ft_puti);
	while (read(STDIN_FILENO, &key, 5) && key[0] != '\r')
	{
		printf("(%d-%d-%d-%d-%d)", key[0], key[1], key[2], key[3], key[4]);
		if (ft_isprint(key[0]))
		{
			//printf("%d ('%c')\n", key, key);
			//line = ft_strapnd(line, key);
			ft_insert(key[0]);
		}
		else
			detect_ctrl(key);
		ft_bzero(key, 5);
	}
	return (line);
}
