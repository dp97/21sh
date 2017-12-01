/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:51:49 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 14:59:51 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	unsigned char			ch;

	s1 = dest;
	s2 = src;
	ch = c;
	if (n)
	{
		while (n != 0)
		{
			if ((*s1++ = *s2++) == ch)
				return (s1);
			n--;
		}
	}
	return (0);
}
