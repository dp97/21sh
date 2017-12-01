/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:51:23 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 15:01:07 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_part_2(unsigned long long value, \
		char c, int *flag, char *buf)
{
	if (c == 'b')
		ft_itoa_base(buf, value, 2, 0);
	else if (c == 'i')
		convert_i(buf, flag, value);
	else if (c == 'u')
		convert_u(buf, flag, value);
	else if (c == 'p')
		convert_p(buf, flag, value, 0);
	else
		return (-1);
	return (1);
}

static int	num_part_1(unsigned long long value, \
		char c, int *flag, char *buf)
{
	if (c == 'x' || c == 'X')
	{
		if (convert_x(buf, flag, value, (c == 'X') ? 1 : 0) == 0)
		{
			free(buf);
			buf = NULL;
			return (0);
		}
	}
	else if (c == 'o')
	{
		if (*flag & ALT_FORM)
			if (value == 0)
			{
				*flag |= STRING_FLAG;
				dp_strcpy(buf, "0");
				return (2);
			}
		convert_o(buf, flag, value);
	}
	else if (num_part_2(value, c, flag, buf))
		;
	else
		return (-1);
	return (1);
}

char		*number_to_char(unsigned long long value, \
		char c, int *width, int *flag)
{
	char	*buf;
	char	alt_form[2];
	short	i;

	i = 0;
	alt_form[0] = 0;
	if ((buf = (char *)malloc(sizeof(char) * 40)) == NULL)
		return (0);
	if ((i = num_part_1(value, c, flag, buf)) != -1)
	{
		if (i == 2)
			return (buf);
		else if (!i)
			return (0);
	}
	if (*flag & MAX_PRINT && (width[1] == 0) && value == 0)
	{
		free(buf);
		buf = 0;
	}
	return (buf);
}
