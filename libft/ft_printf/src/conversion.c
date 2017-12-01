/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 10:11:29 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/31 10:32:35 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dp_add_comma(char *s)
{
	int		len;
	int		i;

	len = ft_len(s);
	while (len >= 0)
	{
		len -= 3;
		if (len > 0)
		{
			i = ft_len(s);
			while (i >= len)
			{
				s[i] = s[i - 1];
				i--;
			}
			s[len] = ',';
		}
	}
}

void		convert_u(char *buf, int *flag, unsigned long long value)
{
	ft_itoa_base(buf, value, 10, 0);
	if (*flag & COMMA_FLAG)
		dp_add_comma(buf);
}

void		convert_i(char *buf, int *flag, unsigned long long value)
{
	int		i;

	i = 0;
	if ((long long)value < 0)
	{
		dp_strcpy(buf, "-");
		value = -value;
		i = 1;
	}
	else if (*flag & PLUS_SIGN)
	{
		dp_strcpy(buf, "+");
		i = 1;
	}
	else if (*flag & SPACE_FLAG && (!(*flag & MAX_PRINT)))
	{
		dp_strcpy(buf, " ");
		i = 1;
	}
	if (i)
		*flag |= SHOW_SIGN;
	ft_itoa_base(&buf[i], value, 10, 0);
	if (*flag & COMMA_FLAG)
		dp_add_comma(buf);
}

void		convert_o(char *buf, int *flag, unsigned long long value)
{
	int		i;

	i = 0;
	if (*flag & ALT_FORM)
	{
		dp_strcpy(buf, "0");
		i = 1;
	}
	ft_itoa_base(&buf[i], value, 8, 0);
}

int			convert_x(char *buf, int *flag, \
		unsigned long long value, short up_low)
{
	int		i;

	i = 0;
	if (*flag & ALT_FORM)
	{
		if (value == 0 && *flag & MAX_PRINT)
			return (0);
		else if (value == 0)
		{
			dp_strcpy(buf, "0");
			return (1);
		}
		if (up_low)
			dp_strcpy(buf, "0X");
		else
			dp_strcpy(buf, "0x");
		i = 2;
	}
	ft_itoa_base(&buf[i], value, 16, up_low);
	return (1);
}
