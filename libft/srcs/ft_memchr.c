/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:24:00 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 14:36:38 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s1;
	size_t		i;

	i = 0;
	s1 = (const char *)s;
	while (i < n)
	{
		if (s1[i] == c)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}
