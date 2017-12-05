/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:32:59 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/05 12:55:19 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H
# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO
# include "libft.h"
# include <termios.h>

#include <printf.h>

void	fatal(char *pre_message, char *message);
void	find();
/*
**	tty.c
**		- Handle the terminal device.
*/
void	tty_enable_raw();
void	tty_disable_raw();
#endif
