/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:13:33 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 11:51:38 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_history(t_cmd **history)
{
	short	position;
	short	counter;

	counter = 0;
	position = FIFO_SIZE;
	while ((*history)[counter].id != 0 && counter < FIFO_SIZE)
	{
		if ((*history)[counter].id < position + 1)
			position = (*history)[counter].id - 1;
		++counter;
	}
	while (counter)
	{
		printf("%6d\t%s\t%s\n", (*history)[position].id, \
				(*history)[position].time, (*history)[position].line);
		if (++position == FIFO_SIZE \
				&& (*history)[position - 1].id < (*history)[0].id)
			position = 0;
		--counter;
	}
	return (0);
}
