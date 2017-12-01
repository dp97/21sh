/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:46:56 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 15:06:18 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	pos;
	size_t	i;

	i = 0;
	pos = 0;
	if ((len = ft_strlen(s2)) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[pos] == s1[i + pos] && n > (i + pos))
		{
			if (s2[pos + 1] == '\0')
				return ((char *)&s1[i]);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (NULL);
}
