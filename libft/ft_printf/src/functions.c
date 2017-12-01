/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:45:26 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 14:52:30 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char				*to_utf8(wchar_t c)
{
	static unsigned char	buff[5];
	unsigned char			*buffer;

	buffer = buff;
	if (c < (1 << 7))
		*buffer++ = (unsigned char)(c);
	else
	{
		if (c < (1 << 11))
			*buffer++ = (unsigned char)((c >> 6) | 0xC0);
		else if (c < (1 << 16))
		{
			*buffer++ = (unsigned char)((c >> 12) | 0xE0);
			*buffer++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		}
		else if (c < (1 << 21))
		{
			*buffer++ = (unsigned char)((c >> 18) | 0xF0);
			*buffer++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
			*buffer++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		}
		*buffer++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*buffer = '\0';
	return (buff);
}

size_t						dp_wcslen(const wchar_t *s)
{
	const wchar_t			*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char						*ft_wide_string(wchar_t *s)
{
	int						i;
	char					*res;

	if (s == NULL)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * (dp_wcslen(s) * 4 + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		i += dp_strcpy(&res[i], (char *)to_utf8(*s));
		s++;
	}
	return (res);
}
