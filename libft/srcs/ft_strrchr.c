/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 14:04:54 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 15:05:56 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*save;

	ch = 0;
	save = (char *)0;
	while (*++s != '\0')
	{
		ch = *s;
		if (ch == c)
			save = (char *)s;
	}
	if (c == '\0')
		return ((char *)s);
	return (save);
}
