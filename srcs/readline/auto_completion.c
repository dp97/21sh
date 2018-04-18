/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:24:20 by dpetrov           #+#    #+#             */
/*   Updated: 2018/04/18 11:35:49 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

/*
** t_cursor is the position of cursor.
** t_chain is lines readed drom input.
*/
void	auto_completion(t_cursor *cursor, t_chain **line)
{
	ft_putstr(getenv("PWD"));
	ft_putstr((*line)->value);
}
