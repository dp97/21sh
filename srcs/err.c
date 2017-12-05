/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 08:59:55 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/05 12:05:55 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_error(char *pre_message, char *message)
{
	if (pre_message)
		ft_putstr_fd(pre_message, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (1);
}

void	fatal(char *pre_message, char *message)
{
	if (pre_message)
		ft_putstr_fd(pre_message, STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
