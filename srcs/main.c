/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:17:14 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 12:33:43 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	*line;
	(void)argc;
	(void)argv;
	(void)env;
	while(1)
	{
		line = ft_readline();
		if (ft_strcmp(line, "exit") == 0)
		{
			ft_putstr(line);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return (0);
}
