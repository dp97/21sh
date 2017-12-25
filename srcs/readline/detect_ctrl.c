/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 12:22:44 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 18:21:55 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		detect_escape(char *ctrl, t_cursor *cursor, t_chain **line, t_flag *flags)
{
	int	ret;

	if (ft_strcmp(ctrl, CTRL_C_KEY) == 0)
	{
		*flags |= CANCEL_FLAG;
		return (EXIT);
	}
	else if ((ret = delete_keys(ctrl, &((*line)->value), cursor)) != NO_MATCH)
	{
		if (ret == EXIT)
		{
			*flags |= EXIT_FLAG;
			return (EXIT);
		}
	}
	else if (shift_plus_arrows(ctrl, cursor, line) != NO_MATCH)
		;
	else if (if_msc_keypad(ctrl, cursor) != NO_MATCH)
		;
	else if (cut_copy_paste(ctrl, *line, cursor) != NO_MATCH)
		;
	else
		return (NO_MATCH);
	return (MATCH);
}
