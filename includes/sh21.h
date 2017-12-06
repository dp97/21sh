/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:32:59 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 19:53:12 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H
# define PROMPT	"$> "
# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO
# include "libft.h"
# include <termios.h>
# include <term.h>

#include <stdio.h>
#include <curses.h>
typedef struct	s_cupos
{
	int			row;
	short		col_start;
	int         col;
	int			col_end;
}				t_cupos;

void	fatal(char *pre_message, char *message);
void	find();
void        init_terminal_data(void);
int         ft_puti(int c);
/*
**	tty.c
**		- Handle the terminal device.
*/
void	tty_enable_raw();
void	tty_disable_raw();
/*
**	ft_readline.c
**		- Line reading and editing tool.
*/
char	*ft_readline(void);
/*
**	exec_ctrl.c
**		- Execute control characters.
*/
void	ft_insert(char key);
void	del_char(t_cupos *cursor, short which);
/*
**	detect_ctrl.c
**		- Detect which control char was pressed.
*/
void	detect_ctrl(char *ctrl, t_cupos *cursor);
/*
** 	arrows.c
** 		- Detect which arraw was pressed.
*/
int	if_keypad(char *ctrl, t_cupos *cursor);
int	move_cursor_left(t_cupos *cursor);
#endif
