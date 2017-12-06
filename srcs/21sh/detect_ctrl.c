/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:22:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 14:45:01 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	detect_ctrl(char *ctrl)
{
//	printf("{%c}", ctrl);
	/*if (ctrl[0] == 127)
	{
		del_char();
	}
	else */if (ctrl[0] == 3)
	{
		tty_disable_raw();
		exit(EXIT_SUCCESS);
	}

	if (ft_strcmp(tgetstr("ku", 0), ctrl) == 0)
		tputs(tgetstr("up", 0), 1, ft_puti);
	else if (ft_strcmp(tgetstr("kd", 0), ctrl) == 0)
		tputs(tgetstr("do", 0), 1, ft_puti);
	else if (ft_strcmp(tgetstr("kr", 0), ctrl) == 0)
		tputs(tgetstr("nd", 0), 1, ft_puti);
	else if (ft_strcmp(tgetstr("kl", 0), ctrl) == 0)
		tputs(tgetstr("le", 0), 1, ft_puti);

	//char *key = tgetstr("kl", 0);
	//printf("/%d-%d-%d-%d-%d/", key[0], key[1], key[2], key[3], key[4]);
}
