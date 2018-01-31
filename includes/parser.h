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
# define STD_NEXT	6
# define STD_PREV	7
# include "libft.h"
# include "tokening.h"
# include "minishell.h"
typedef struct		s_scmd
{
	char			**argv;
	int				in;
	int				out;
	int				err;
	struct s_scmd	*next;
}					t_scmd;

typedef struct		s_cmd
{
	t_scmd			*by_one;
	struct s_cmd	*next;
}					t_cmd;

t_cmd				*parser(t_token *cmd);
void				ft_delcmds(t_cmd **cmds);
/*
**	Handleres for t_scmd and t_cmd structures.
*/
t_cmd				*new_cmd(void);
t_scmd				*new_scmd(void);
t_scmd				*add_scmd(t_scmd *head, t_scmd *new, int ioe);
t_cmd				*add_cmd(t_cmd *head, t_cmd *new);
#endif
