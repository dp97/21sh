/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 19:28:16 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/19 09:27:26 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*src;
	char	*dest;
	size_t	i;

	i = -1;
	src = (char *)s2;
	dest = (char *)s1;
	if (src < dest)
	{
		while ((int)(--n) >= 0)
			*(dest + n) = *(src + n);
	}
	else
	{
		while (++i < n)
			*(dest + i) = *(src + i);
	}
	return (s1);
}
