/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dollar_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:29:02 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/02 14:34:34 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void		ft_extend(char **dest, char *chunk, int start, int size)
{
	char	tmp[ft_strlen(*dest) - size + 2 + ft_strlen(chunk)];
	int		tmp_size;

	ft_strncpy(tmp, *dest, start);
	tmp_size = ft_strlen(chunk);
	ft_strcpy(&tmp[start], chunk);
	tmp_size += start;
	ft_strcpy(&tmp[tmp_size], &(*dest)[start + size + 1]);
	tmp_size += ft_strlen(&(*dest)[start + size + 1]);
	tmp[tmp_size] = '\0';
	free(*dest);
	*dest = strdup(tmp);
}
