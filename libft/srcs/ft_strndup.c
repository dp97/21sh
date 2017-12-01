/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:30:25 by dpetrov           #+#    #+#             */
/*   Updated: 2016/11/03 15:43:22 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2[len] = '\0';
	return ((char *)ft_memcpy(s2, s1, len));
}
