/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stredit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 09:05:46 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 12:09:13 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Edit a string:
**		1 - insert a char at a given position.
*/
#include<stdio.h>
int			ft_strichar(char **s, int pos, char c)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	char *fu = *s;
	if (fu)
		while (fu[len])
			len++;
	ft_putchar('C');
	if ((new = ft_strnew(len + 2)) == NULL)
		return (1);
	ft_putchar('A');
	if (*s == NULL)
	{
		new[0] = c;
		*s = new;
		return (0);
	}
	//new = ft_strncpy(new, *s, pos);
	new[pos] = c;
	//new = ft_strcpy(new, s[pos]);
	ft_strdel(s);
	*s = new;
	return (0);
}

int			ft_strdchar(char **s, int pos)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((new = ft_strnew(ft_strlen(*s) - 1)) == NULL)
		return (1);
	while ((*s)[i])
	{
		if (i != pos)
			new[j++] = (*s)[i];
		++i;
	}
	new[j] = '\0';
	ft_strdel(s);
	*s = new;
	return (0);
}
