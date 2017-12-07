/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:57:55 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 18:01:28 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		init_terminal_data(void)
{
	char	*term_type;
	int		success;

	if ((term_type = getenv("TERM")) == NULL)
		fatal(NULL, "init: Env 'TERM' not defined.\n");
	success = tgetent(0, term_type);
	if (success < 0)
		fatal(NULL, "init: Could not access terminfo database\n");
	else if (success == 0)
		fatal(NULL, "init: Terminal type is not defined\n");
}
