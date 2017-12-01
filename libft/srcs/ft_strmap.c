/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 01:35:09 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 17:00:18 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*r;

	i = 0;
	if (!s || !f)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (r)
	{
		while (s[i])
		{
			r[i] = (*f)(s[i]);
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
