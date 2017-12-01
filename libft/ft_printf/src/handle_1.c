/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:49:29 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/02 11:19:37 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						handle_d_i(const char *format, va_list args, \
		int *flag, int width[2])
{
	unsigned long long	nb;
	char				*s;

	if (*format == 'D')
		*flag |= L_FLAG;
	if (*flag & MAX_PRINT)
		*flag |= ZERO_FLAG;
	if (*flag & LL_FLAG)
		nb = va_arg(args, long long);
	else if (*flag & L_FLAG)
		nb = va_arg(args, long);
	else if (*flag & SIZE_T)
		nb = va_arg(args, ssize_t);
	else if (*flag & INTMAX_T)
		nb = va_arg(args, intmax_t);
	else if (*flag & HH_FLAG)
		nb = (signed char)va_arg(args, int);
	else if (*flag & H_FLAG)
		nb = (short)va_arg(args, int);
	else
		nb = va_arg(args, int);
	s = number_to_char(nb, 'i', width, flag);
	return (ft_prints(&s, *flag, width));
}

int						handle_u(const char *format, va_list args, \
		int *flag, int width[2])
{
	unsigned long long	nb;
	char				*s;

	if (*format == 'U')
		*flag |= L_FLAG;
	if (*flag & MAX_PRINT)
		*flag |= ZERO_FLAG;
	if (*flag & LL_FLAG)
		nb = va_arg(args, unsigned long long);
	else if (*flag & L_FLAG)
		nb = va_arg(args, unsigned long);
	else if (*flag & HH_FLAG)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (*flag & H_FLAG)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (*flag & INTMAX_T)
		nb = va_arg(args, uintmax_t);
	else if (*flag & SIZE_T)
		nb = va_arg(args, size_t);
	else
		nb = va_arg(args, unsigned int);
	s = number_to_char(nb, 'u', width, flag);
	return (ft_prints(&s, *flag, width));
}

int						handle_o(const char *format, va_list args, \
		int *flag, int width[2])
{
	unsigned long long	nb;
	char				*s;

	if (*format == 'O')
		*flag |= L_FLAG;
	if (*flag & MAX_PRINT)
		*flag |= ZERO_FLAG;
	if (*flag & LL_FLAG)
		nb = va_arg(args, unsigned long long);
	else if (*flag & L_FLAG)
		nb = va_arg(args, unsigned long);
	else if (*flag & HH_FLAG)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (*flag & H_FLAG)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (*flag & INTMAX_T)
		nb = va_arg(args, uintmax_t);
	else if (*flag & SIZE_T)
		nb = va_arg(args, size_t);
	else
		nb = va_arg(args, unsigned int);
	s = number_to_char(nb, 'o', width, flag);
	return (ft_prints(&s, *flag, width));
}

int						handle_x_p(const char *format, va_list args, \
		int *flag, int width[2])
{
	unsigned long long	nb;
	char				*s;

	if (*format == 'p')
		*flag |= ALT_FORM | L_FLAG;
	if (*flag & MAX_PRINT)
		*flag |= ZERO_FLAG;
	if (*flag & LL_FLAG)
		nb = va_arg(args, unsigned long long);
	else if (*flag & L_FLAG)
		nb = va_arg(args, unsigned long);
	else if (*flag & HH_FLAG)
		nb = (unsigned char)va_arg(args, unsigned int);
	else if (*flag & H_FLAG)
		nb = (unsigned short)va_arg(args, unsigned int);
	else if (*flag & SIZE_T)
		nb = va_arg(args, size_t);
	else if (*flag & INTMAX_T)
		nb = va_arg(args, uintmax_t);
	else
		nb = va_arg(args, unsigned int);
	s = number_to_char(nb, *format, width, flag);
	return (ft_prints(&s, *flag, width));
}

int						handle_f(const char *format, va_list args, \
		int *flag, int width[2])
{
	char				*s;

	s = float_to_char((*flag & L_FLOAT_FLAG) ? va_arg(args, long double) \
			: va_arg(args, double), *format, width, flag);
	return (ft_prints(&s, *flag, width));
}
