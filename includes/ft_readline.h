/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:56:19 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:45:39 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# define DEBUG			0
# define PROMPT			"myShell$> "
# define HISTORY_PATH	".history"
# define LOG_PATH		".log"
# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO
# include "libft.h"
# include "input_stream.h"
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <fcntl.h>

#include <stdio.h>
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
int    ft_puti(int c);
/*
**	tty.c
**		- Handle the terminal device.
*/
void			tty_enable_raw();
void			tty_disable_raw();
/*
**	ft_readline.c
**		- Line reading and editing tool.
*/
char			*ft_readline(void);
/*
**	exec_ctrl.c
**		- Execute control characters.
*/
void			ft_insert(char *line, t_cupos *cursor);
int				del_char(t_cupos *cursor, short which, t_cmds **head);
/*
**	detect_ctrl.c
**		- Detect which control char was pressed.
*/
void			detect_ctrl(char *ctrl, t_cupos *cursor, t_cmds **history);
/*
** 	arrows.c
** 		- Detect which arraw was pressed.
*/
int				if_keypad(char *ctrl, t_cupos *cursor, t_cmds *history);
int				move_cursor_left(t_cupos *cursor);
/*
**	Logs the errors in file pointed by LOG_PATH macro.
*/
void			ft_log(char *msg, short critical);
/*
**	history.c
**		- Handle the history.
*/
t_cmds			*ft_init_history(void);
void			ft_update_history(char *line);
#endif
