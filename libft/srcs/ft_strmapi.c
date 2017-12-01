/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 02:04:01 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/17 17:01:02 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			r[i] = (*f)(i, s[i]);
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
