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
# define NEWLINE			"\n\r"
# define PROMPT				"myShell$> "
# define BACKSLASH_PROMPT	"$> "
# define HISTORY_PATH	".history"
# define LOG_PATH		".log"
# define RET_OK		0
# define RET_ERR	1
# define RET_MIRR	-1
# define DONE			0
# define ERR			1
# define NOTHING_DONE	2
# define CH_CURSOR_COL	tgetstr("ch", 0)
# define CURSOR_UP		tgetstr("up", 0)
# define CURSOR_DO		tgetstr("do", 0)
# define DELETE_CHAR	tgetstr("dc", 0)
# define ARROW_LEFT		tgetstr("kl", 0)
# define ARROW_RIGHT	tgetstr("kr", 0)
# define ARROW_UP		tgetstr("ku", 0)
# define ARROW_DOWN		tgetstr("kd", 0)
# define SHIFT_LEFT		"\e[1;2D"
# define SHIFT_RIGHT	"\e[1;2C"
# define SHIFT_UP		"\e[1;2A"
# define SHIFT_DOWN		"\e[1;2B"
# define CTRL_D_KEY		"\x4"
# define CTRL_C_KEY		"\x3"
# define BACKSPACE_KEY	"\x7F"
# define HOME_KEY		tgetstr("kh", 0)
# define END_KEY		tgetstr("@7", 0)
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

int				ft_insert_char(char **line, t_cursor *cursor, char input);
void			ft_erarse_line(t_cursor *cursor);
void			ft_print_line(t_cursor *cursor, char *line);
void			ft_replace_line(char *line, t_cursor *cursor);
/*
**	s_chain.c
**		- Fuctions to handle operations on s_chain.
*/
t_chain			*ft_chainnew(char *value);
void			ft_chainpurge(t_chain **chain);
int				ft_chainadd_front(t_chain **head);
int				ft_chainadd_back(t_chain **head);
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
void			ft_insert(char input, t_cursor *cursor);
int				delete_char(char **line, t_cursor *cursor);
int				backspace_char(char **line, t_cursor *cursor);
/*
**	detect_ctrl.c
**		- Detect which control char was pressed.
*/
void			detect_escape(char *ctrl, t_cursor *cursor, t_chain **line);
/*
** 	arrows.c
** 		- Detect which arraw was pressed.
*/
int				arrows(char *ctrl, t_cursor *cursor, t_chain **line, t_chain **history);
/*	shift_plus_arrows.c
**		- Detect if a arrow was pressed in combination with control key.
*/
int				shift_plus_arrows(char *ctrl, t_cursor *cursor, t_chain **line);
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
/*	msc_keypad.c
**		- Handles 'Home', 'End' keys.
*/
int				if_msc_keypad(char *key, t_cursor *cursor);
#endif
