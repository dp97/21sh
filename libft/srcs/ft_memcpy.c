/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 14:28:46 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/07 15:14:11 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	i = 0;
	s1 = str1;
	s2 = str2;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (str1);
}
