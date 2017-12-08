/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stream.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:54:04 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:55:34 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STREAM_H
# define INPUT_STREAM_H
# include <stdlib.h>
# include "libft.h"
/*
**	Struct to storage by character.
*/
typedef struct		s_cmds
{
	char			*value;
	short			iscurrent;
	struct s_cmds	*prev;
	struct s_cmds	*next;
}					t_cmds;

/*
**	Create new container.
*/
t_cmds				*ft_cmdnew(char *value);
/*
**	Delete containers and free the memory.
*/
void				ft_purgecmds(t_cmds **head);
/*
**	Add a container to the end of the list,
**	  inclusive if head is NULL.
**		- Return 1 on success, 0 on failure.
*/
int					ft_cmdadd(t_cmds **head, t_cmds *new);
int					ft_cmdprepend(t_cmds **head, t_cmds *new);
/*
**	Delete a container at a given position in list.
*/
void				ft_cmddel(t_cmds **head, int this);
#endif
