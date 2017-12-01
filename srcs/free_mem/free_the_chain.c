/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_the_chain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:55:28 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/01 16:04:45 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_mem.h"

void	free_the_chain(t_cmd *history, int size)
{
	int	i;

	i = 0;
	while (i < FIFO_SIZE)
	{
		free(history[i].line);
		if (++i == size)
			break ;
	}
}
