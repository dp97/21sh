/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:44:09 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/30 08:44:12 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char ***argv)
{
	int	nflag;
	int	i;

	i = 1;
	if ((*argv)[1] && strcmp((*argv)[1], "-n") == 0)
	{
		++i;
		nflag = 1;
	}
	else
		nflag = 0;
	while ((*argv)[i])
	{
		ft_putstr_fd((*argv)[i], STDOUT_FILENO);
		++i;
		if ((*argv)[i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (nflag == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
