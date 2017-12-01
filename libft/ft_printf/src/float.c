/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 11:22:33 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/02 15:06:36 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				check_nan(t_convert d, char *res, int *flag)
{
	short int			i;

	i = 0;
	while (d.parts.exponent & 1 << i)
	{
		if (i == 7)
		{
			if (d.parts.quit_nan)
				dp_strcpy(res, "nan");
			else
			{
				if (d.parts.sign)
					dp_strcpy(res, "-inf");
				else
					dp_strcpy(res, (*flag & PLUS_SIGN) ? "+inf" : "inf");
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static int				nbr_after_dot(int after_point, char *res, long double n)
{
	short				tmp;
	int					i;

	i = 0;
	while (after_point--)
	{
		if (after_point == 1)
			n += 0.005;
		tmp = n *= 10;
		res[i++] = tmp + '0';
		n -= tmp;
	}
	return (i);
}

int						dp_ftoa(long double n, char *res, \
		short after_point, int *flag)
{
	unsigned long long	full;
	t_convert			d;

	d.f = n;
	if (check_nan(d, res, flag))
		return (0);
	if (d.parts.sign)
	{
		*res++ = '-';
		n = -n;
	}
	full = n;
	n -= full;
	ft_itoa_base(res, full, 10, 0);
	while (*res && after_point)
		res++;
	if (after_point)
		*res++ = '.';
	else
		*res++ = (n + 0.5) + '0';
	if (after_point)
		res += nbr_after_dot(after_point, res, n);
	*res = '\0';
	return (1);
}

char					*float_to_char(long double value, char c, \
		int *width, int *flag)
{
	char				*res;

	if ((res = (char *)malloc(sizeof(char) * \
					((width[1] > 56) ? width[1] : 56))) == NULL)
		return (NULL);
	if (dp_ftoa(value, res, (*flag & MAX_PRINT) ? width[1] : 6, flag))
		width[1] = 0;
	if (c == 'F')
		ft_str_case(res, 1);
	return (res);
}
