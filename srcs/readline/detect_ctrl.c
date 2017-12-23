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

int		detect_escape(char *ctrl, t_cursor *cursor, t_chain **line)
{
	int	ret;

	if (ft_strcmp(ctrl, CTRL_C_KEY) == 0)
		ft_putstrstr("\n\r", PROMPT);
	else if (ctrl[0] == 5)
	{
		tty_disable_raw();
		exit(EXIT_SUCCESS);
	}
	else if ((ret = delete_keys(ctrl, &((*line)->value), cursor)) != NO_MATCH)
		return (ret);
	else if (shift_plus_arrows(ctrl, cursor, line) != NO_MATCH)
		return (MATCH);
	else if (if_msc_keypad(ctrl, cursor) == DONE)
		return (MATCH);
	else if (cut_copy_paste(ctrl, *line, cursor) == MATCH)
		return (MATCH);

	//char *key = tgetstr("kl", 0);
//	printf("/%d-%c-%c-%c-%c-%c/", ctrl[0], ctrl[1], ctrl[2], ctrl[3], ctrl[4], ctrl[5]);
	return (MATCH);
}
