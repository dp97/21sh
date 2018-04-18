/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:32:09 by dpetrov           #+#    #+#             */
/*   Updated: 2018/04/18 11:11:34 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void	find(void)
{
	char	*path;

	if (isatty(STDIN_FILENO))
	{
		if ((path = ttyname(STDIN_FILENO)) == NULL)
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
	raw.c_iflag &= ~(ICRNL | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void				tty_disable_raw()
{
	struct termios	cooked;

	tcgetattr(STDIN_FILENO, &cooked);
	cooked.c_iflag |= ICRNL | IXON;
	cooked.c_oflag |= OPOST;
	cooked.c_lflag |= ECHO | ICANON | IEXTEN | ISIG;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &cooked);
}
