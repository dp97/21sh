/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:21:35 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 13:44:06 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	if_not_an_specifier(const char *format, int flag, int width[2])
{
	char	*form;

	form = dp_strndup(format, 1);
	return (ft_prints(&form, flag, width));
}

static int	ft_specifiers(const char *format, va_list args, \
		int width[2], int flag)
{
	int		char_written;

	char_written = 0;
	if (*format == 's' || *format == 'S')
		char_written += handle_s(format, args, &flag, width);
	else if (*format == 'c' || *format == 'C')
		char_written += handle_c(format, args, &flag, width);
	else if (*format == 'd' || *format == 'i' || *format == 'D')
		char_written += handle_d_i(format, args, &flag, width);
	else if (*format == 'u' || *format == 'U')
		char_written += handle_u(format, args, &flag, width);
	else if (*format == 'o' || *format == 'O')
		char_written += handle_o(format, args, &flag, width);
	else if (*format == 'x' || *format == 'X' || *format == 'p')
		char_written += handle_x_p(format, args, &flag, width);
	else if (*format == 'b')
		char_written += handle_b(format, args, &flag, width);
	else if (*format == 'f' || *format == 'F')
		char_written += handle_f(format, args, &flag, width);
	else if (*format == 'n')
		handle_n(args, &flag, char_written);
	else
		return (if_not_an_specifier(format, flag, width));
	return (char_written);
}

static int	format_goes_up(const char *format, int *var_3, \
		va_list args, int width[2])
{
	int		i;
	char	*s;
	int		tmp;

	i = 1;
	if (format[i] == '\0')
		return (0);
	while ((tmp = ft_flags_1(&format[i], &var_3[2], width, args)) && format[i])
		i += tmp;
	while (ft_modifiers(&format[i], &var_3[2]) && format[i])
		i++;
	while ((tmp = ft_flags_1(&format[i], &var_3[2], width, args)) && format[i])
		i += tmp;
	if (format[i] == '\0')
		return (i);
	else if (format[i] == '%')
	{
		s = dp_strndup("%", 2);
		var_3[1] += ft_prints(&s, var_3[2], width);
	}
	else if (!(var_3[1] += ft_specifiers(&format[i], args, width, var_3[2])))
		return (i);
	return (i);
}

static int	print(const char *format, va_list args)
{
	int		width[2];
	int		ef_cw_nf[3];

	ef_cw_nf[1] = 0;
	ef_cw_nf[0] = 0;
	while (*format)
	{
		ef_cw_nf[2] = 0;
		width[0] = 0;
		width[1] = 0;
		if (*format == '{')
			format += dp_check_color(format, &(ef_cw_nf[0]));
		if (*format == '%')
		{
			format += format_goes_up(format, ef_cw_nf, args, width);
			if (ef_cw_nf[1] == -1 || *format == '\0')
				break ;
		}
		else
			ef_cw_nf[1] += ft_putc(*format);
		format++;
	}
	if (ef_cw_nf[0] & ACTIVE_COLOR)
		ft_printf(COLOR_RESET);
	return (ef_cw_nf[1]);
}

int			ft_printf(const char *format, ...)
{
	int		done;
	va_list	list_pointer;

	va_start(list_pointer, format);
	done = print(format, list_pointer);
	va_end(list_pointer);
	return (done);
}
