/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:31:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 14:16:28 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int			ft_puti(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

static void	ft_mode(char *req)
{
	char	*code;

	code = tgetstr(req, 0);
	if (code == NULL)
	{
		ft_mode("me");
		ft_putstr_fd("not mode", STDIN_FILENO);
	}
	tputs(code, 1, ft_puti);
}

void	del_char()
{
	//ft_mode("dm");
	//ft_mode("dc");
	tputs(tgetstr("dc", 0), 1, ft_puti);
//	ft_mode("ed");
}

void	ft_insert(char key)
{
	ft_mode("im");
	write(STDIN_FILENO, &key, 1);
	tputs(tgetstr("ei", 0), 1, ft_puti);
}
