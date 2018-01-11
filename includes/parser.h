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
# include "libft.h"
# include "tokening.h"
typedef struct		s_cmd
{
	char			**value;
	struct s_cmd	*next;
}					t_cmd;

t_cmd				*parser(t_token *cmd);
void				ft_delcmds(t_cmd **cmds);
#endif
