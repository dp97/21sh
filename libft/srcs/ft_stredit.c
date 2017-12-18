/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stredit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:05:46 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:57:54 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Edit a string:
**		1 - insert a char at a given position, error on insuficient memory.
*/
#include<stdio.h>
int			ft_strichar(char **s, int pos, char c)
{
	char	*new;
	int		len;

	len = ft_strlen(*s);
	if (pos < 0 || pos > len + 1)
		return (0);
	if ((new = ft_strnew(len + 2)) == NULL)
		return (1);
	if (*s == NULL)
	{
		new[0] = c;
		*s = new;
		return (0);
	}
	ft_memcpy(new, *s, pos);
	new[pos] = c;
	ft_memcpy(&new[pos + 1], &(*s)[pos], len - pos + 1);
	ft_strdel(s);
	*s = new;
	return (0);
}

int			ft_strdchar(char **s, int pos)
{
	char	*new;
	int		len;

	if (!s || !*s || pos < 0)
		return (1);
	len = ft_strlen(*s);
	if (len == 1)
	{
		ft_strdel(s);
		return (0);
	}
	if (pos > len || (new = ft_strnew(len - 1)) == NULL)
		return (1);
	ft_strncpy(new, *s, pos);
	ft_strcpy(&new[pos], &((*s)[pos + 1]));
	ft_strdel(s);
	*s = new;
	return (0);
}
