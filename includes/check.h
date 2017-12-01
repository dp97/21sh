/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 09:03:13 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/02 14:34:43 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H
# include "libft.h"

char		*check_line(char *line, short *pos);
int			check_for_variables(char **token, char **env);
char		*ft_getenv(char *name, char **env);
void		ft_extend(char **dest, char *chunk, int start, int size);
/*
**  ERROR PRINTING !!!
*/
int			check_error(char *pre_message, char *message);
#endif
