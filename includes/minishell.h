/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:46:42 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 17:30:58 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>
# include <time.h>

# define PATH_MAX	4096
# define FIFO_SIZE	100
# define TOKENS		65

typedef struct		s_cmd
{
	int				id;
	char			time[5];
	char			*line;
	char			**tokens;
}					t_cmd;

int					g_sig;

char				*ft_read_line(void);
void				ft_loop(char **env);
char				**ft_get_args(char **env, char *line);
int					ft_error(char *message);
int					ft_execute(char **args, char **env, t_cmd *history);
int					ft_launch(char **args, char **env);
char				*my_read_line(void);
void				sig_handler(int signo);
void				set_null_id(t_cmd *history);
void				capture_time(char *buf);
/*
**	Builtins !
*/
int					ft_exit(char **args);
int					ft_cd(char **args, char **env);
int					ft_env(char **args, char **env);
int					ft_setenv(char **args, char **env);
int					ft_unsetenv(char **args, char **env);
int					ft_echo(char ***argv);
/*
**	My Builtins ! + BONUS
*/
int					ft_printenv(char **args, char **env);
char				*ft_getenv(char *name, char **env);
int					ft_history(t_cmd **history);
/*
**  ERROR PRINTING !!!
*/
int					check_error(char *pre_message, char *message);
#endif
