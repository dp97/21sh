/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:32:09 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/05 13:23:45 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	find(void)
{
	char	*path;

	printf("{%d}", ttyslot());
	if (isatty(STDIN))
	{
		if ((path = ttyname(STDIN)) == NULL)
			fatal("tty:", "Could not find terminal device.\n");
	}
	else
		fatal("tty:", "Not on a terminal\n");
	ft_putstr(path);
}

void				tty_enable_raw()
{
	struct termios	raw;

	tcgetattr(STDIN_FILENO, &raw);
	raw.c_iflag &= ~(ICRNL);
	raw.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void				tty_disable_raw()
{
	struct termios	cooked;

	tcgetattr(STDIN_FILENO, &cooked);
	cooked.c_iflag |= ICRNL;
	cooked.c_lflag |= ECHO | ICANON;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &cooked);
}
