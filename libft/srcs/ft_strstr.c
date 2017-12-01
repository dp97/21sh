/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 14:22:36 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/10 16:41:21 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		len;
	int		pos;

	i = 0;
	pos = 0;
	if ((len = ft_strlen(s2)) == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[pos] == s1[i + pos])
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
