/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:56:19 by dpetrov           #+#    #+#             */
/*   Updated: 2018/01/26 13:50:27 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H
# define DEBUG			0
# define NEWLINE			"\n\r"
# define NAME				"21sh"
# define PROMPT				"myShell$> "
# define BACKSLASH_PROMPT	"$> "
# define QUOTE_PROMPT		"quote> "
# define DQUOTE_PROMPT		"dquote> "
# define HISTORY_PATH	".history"
# define LOG_PATH		".log"
# define RET_OK		0
# define RET_ERR	1
# define RET_MIRR	-1
# define YES	1
# define NO		0
# define DONE			0
# define ERR			1
# define NOTHING_DONE	2
# define MATCH			3
# define NO_MATCH		4
# define EXIT			5

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
# define SHIFT_UP			"\e[1;2A"
# define SHIFT_DOWN		"\e[1;2B"

# define CTRL_A_KEY		"\x1"	/*begin of line*/
# define CTRL_E_KEY		"\x5"	/*end of line*/
# define CTRL_H_KEY		"\x8"	/*backspace char*/
# define CTRL_W_KEY		"\x17"	/*cutcopy word before cursor*/
# define CTRL_K_KEY		"\xB"	/*....... part line after cursor*/
# define CTRL_U_KEY		"\x15"	/*........ part line before cursor*/
# define CTRL_Y_KEY		"\x19"	/*paste copied line from clipboard*/
# define CTRL_D_KEY		"\x4"	/*delete char+exit shell*/
# define CTRL_C_KEY		"\x3"	/*Cancel command + kill process*/

# define BACKSPACE	CTRL_H_KEY
# define CC_BACK_W	CTRL_W_KEY
# define CC_FRONT	CTRL_K_KEY
# define CC_BACK	CTRL_U_KEY
# define CC_PASTE	CTRL_Y_KEY
# define A_LEFT_W	SHIFT_LEFT
# define M_BEGIN	CTRL_A_KEY
# define M_END		CTRL_E_KEY

# define BACKSPACE_KEY	"\x7F"
# define DELETE_KEY		tgetstr("kD", 0)
# define HOME_KEY		tgetstr("kh", 0)
# define END_KEY		tgetstr("@7", 0)

typedef short	t_flag;
# define QUOTE_FLAG		1
# define DQUOTE_FLAG	2
# define EXIT_FLAG		4
# define CANCEL_FLAG	8

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
int		ft_posinstr(t_cursor cursor);
int				ft_insert_char(char **line, t_cursor *cursor, char input);
void			ft_erarse_line(t_cursor *cursor);
void			ft_print_line(t_cursor *cursor, char *line);
void			ft_replace_line(char *line, t_cursor *cursor);
int				check_for_backslashend(t_chain *line, short last);

/*
**
*/
int				delete_keys(char *ctrl, char **l, t_cursor *cursor);
/*
**	quotes.c
**		- Parse all lines for quotes and double quotes.
*/
void			proccess_line_for_quotes(t_chain *line, t_flag *flags);
/*
**	cut_copy_paste.c
**		- Functions to handle cuting, copying and paste.
*/
int				cut_copy_paste(char *ctrl, t_chain *line, t_cursor *cursor);
/*
**	s_chain.c
**		- Fuctions to handle operations on s_chain.
*/
t_chain			*ft_chainnew(char *value);
void			ft_chainpurge(t_chain **chain);
int				ft_chainadd_front(t_chain **chain);
int				ft_chainadd_back(t_chain **chain);
t_chain			*ft_chain_gethead(t_chain *chain);
t_chain			*ft_chain_gettail(t_chain *chain);
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
int				detect_escape(char *ctrl, t_cursor *cursor, t_chain **line, t_flag *flags);
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
void			ft_puterr(char *pre_message, char *message);
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
