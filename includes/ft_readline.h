/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:56:19 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 19:28:05 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# define DEBUG			0
# define PROMPT			"myShell$> "
# define HISTORY_PATH	".history"
# define LOG_PATH		".log"
# define RET_OK		0
# define RET_ERR	1
# define RET_MIRR	-1
# define ARROW_LEFT		tgetstr("kl", 0)
# define ARROW_RIGHT	tgetstr("kr", 0)
# define ARROW_UP		tgetstr("ku", 0)
# define ARROW_DOWN		tgetstr("kd", 0)
# define SHIFT_LEFT		"\e[1;2D"
# define SHIFT_RIGHT	"\e[1;2C"
# define SHIFT_UP		"\e[1;2A"
# define SHIFT_DOWN		"\e[1;2B"
# include "libft.h"
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

typedef struct		s_chain
{
	char			*value;
	struct s_chain	*prev;
	struct s_chain	*next;
}					t_chain;

void	fatal(char *pre_message, char *message);
void	find();
void        init_terminal_data(void);
void	infoo(char *key);
int    ft_puti(int c);
int				print(char **line, t_cursor **cursor, char input);
int				calc_pos(t_cursor *cursor);
int				calc_pos_relative(t_cursor *cursor, int to);
/*
**	s_chain.c
**		- Fuctions to handle operations on s_chain.
*/
t_chain			*ft_chainnew(char *value);
void			ft_chainpurge(t_chain **chain);
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
void			ft_insert(char input, t_cursor **cursor);
int				del_char(t_cursor **cursor, short which, char **line);
/*
**	detect_ctrl.c
**		- Detect which control char was pressed.
*/
void			detect_ctrl(char *ctrl, t_cursor **cursor, t_chain **line);
/*
** 	arrows.c
** 		- Detect which arraw was pressed.
*/
int				arrows(char *ctrl, t_cursor **cursor, t_chain **line);
/*	shift_plus_arrows.c
**		- Detect if a arrow was pressed in combination with control key.
*/
int				shift_plus_arrows(char *ctrl, t_cursor **cursor, t_chain **line);
/*
**	Logs the errors in file pointed by LOG_PATH macro.
*/
void			ft_log(char *msg, short critical);
/*
**	history.c
**		- Handle the history.
*/
t_chain			*ft_init_history(void);
void			ft_update_history(char *line);
/*	copy_paste.c
**		- copy, cut and paste.
*/
int				if_copy_paste(char *key, t_cursor **cursor, t_chain **line, char **in_memory);
/*	msc_keypad.c
**		- Handles 'Home', 'End' keys.
*/
int				if_msc_keypad(char *key, t_cursor **cursor);
#endif
