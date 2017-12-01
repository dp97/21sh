/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:12:48 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 13:09:30 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			dp_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while ((dst[i] = *src++) != 0)
		i++;
	return (i);
}

char		*ft_str_case(char *s, int up_or_low)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (up_or_low)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		else
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
		}
		i++;
	}
	return (s);
}

int			ft_len(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int			ft_puts(char *s, int len)
{
	int		i;

	i = 0;
	while (s[i] && i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

char		*dp_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_len((char *)s1);
	if (n < len)
		len = n;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2[len] = '\0';
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
