/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:07:02 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 13:52:58 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define SEPARATOR	0
# define PIPE		1
# define IN			2
# define DIN		3
# define OUT		4
# define DOUT		5
# define FROM_PIPE	6
# define TO_PIPE	7
# define TO_FILE	8
# define ATO_FILE	9
# define FROM_FILE	10
# define FROM_HEREFILE	11
# define NO_APPEND      12
# include "libft.h"
# include "tokening.h"
# include "minishell.h"
typedef struct		s_scmd
{
	char			**argv;
	int				open_flags;
	char			*output;
	int				out;
	char			*input;
	int				in;
	char			*error;
	int				err;
	struct s_scmd	*next;
}					t_scmd;

typedef struct		s_cmd
{
	t_scmd			*by_one;
	struct s_cmd	*next;
}					t_cmd;

t_cmd				*parser(t_token *cmd);
void 				purge_cmd(t_cmd *cmd);
void 				purge_scmd(t_scmd *scmd);
void destroy_scmd(t_scmd **scmd);
int	prep_redir(t_scmd *whole_scmd, t_scmd *scmd, char *pre, char *post);
/*
**	Handleres for t_scmd and t_cmd structures.
*/
t_cmd				*new_cmd(void);
t_scmd				*new_scmd(void);
t_scmd				*add_scmd(t_scmd *head, t_scmd *new);
t_cmd				*add_cmd(t_cmd *head, t_cmd *new);
#endif
