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
typedef struct		s_cursor
{
	short			col_start;
	int         	col;
	int				col_end;
	struct s_cursor	*prev;
	struct s_cursor	*next;
}					t_cursor;

void	fatal(char *pre_message, char *message);
void	find();
void        init_terminal_data(void);
void	infoo(char *key);
int    ft_puti(int c);
int				print(t_cmds **history, t_cursor **cursor, char *line);
int				calc_pos(t_cursor *cursor);
int				calc_pos_relative(t_cursor *cursor, int to);
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
void			ft_insert(char *line, t_cursor **cursor);
int				del_char(t_cursor **cursor, short which, char **line);
/*
**	detect_ctrl.c
**		- Detect which control char was pressed.
*/
void			detect_ctrl(char *ctrl, t_cursor **cursor, t_cmds **history);
/*
** 	arrows.c
** 		- Detect which arraw was pressed.
*/
int				if_keypad(char *ctrl, t_cursor **cursor, t_cmds **history);
int				move_cursor_left(t_cursor **cursor);
/*	ctrl_arrows.c
**		- Detect if a arrow was pressed in combination with control key.
*/
int				if_ctrl_keypad(char *key, t_cursor **cursor, t_cmds **history);
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
/*	copy_paste.c
**		- copy, cut and paste.
*/
int				if_copy_paste(char *key, t_cursor **cursor, t_cmds **history, char **in_memory);
/*	msc_keypad.c
**		- Handles 'Home', 'End' keys.
*/
int				if_msc_keypad(char *key, t_cursor **cursor);
#endif
