/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:40:51 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 13:36:48 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handle_b(const char *format, va_list args, int *flag, int width[2])
{
	char	*s;

	if (*flag & MAX_PRINT)
		*flag |= ZERO_FLAG;
	s = number_to_char(va_arg(args, int), *format, width, flag);
	return (ft_prints(&s, *flag, width));
}

int			handle_c(const char *format, va_list args, int *flag, int width[2])
{
	char	ch;
	char	*s;
	int		char_written;

	char_written = 0;
	if (*format == 'C' || (*flag & L_FLAG))
	{
		s = (char *)to_utf8((wint_t)va_arg(args, int));
		*flag |= STRING_FLAG;
	}
	else
	{
		ch = va_arg(args, int);
		if ((s = (char *)malloc(sizeof(char) * 5)) == NULL)
			return (0);
		*s = ch;
		if (!*s)
		{
			char_written++;
			if (width[0])
				width[0] -= 1;
		}
	}
	char_written += ft_prints(&s, *flag, width);
	return (char_written);
}

int			handle_s(const char *format, va_list args, int *flag, int width[2])
{
	char	*s;

	if ((*flag & L_FLAG) || *format == 'S')
		s = ft_wide_string(va_arg(args, wchar_t *));
	else
	{
		s = va_arg(args, char *);
		if (s != 0)
			*flag |= STRING_FLAG;
	}
	if (s == 0)
		s = dp_strndup("(null)", 6);
	else if (*flag & MAX_PRINT)
		s = dp_strndup(s, width[1]);
	return (ft_prints(&s, *flag, width));
}

void		handle_n(va_list args, int *flag, int char_written)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (*flag & LL_FLAG)
		*(long long *)ptr = char_written;
	else if (*flag & L_FLAG)
		*(long *)ptr = char_written;
	else if (*flag & HH_FLAG)
		*(signed char *)ptr = char_written;
	else if (*flag & H_FLAG)
		*(char *)ptr = char_written;
	else if (*flag & INTMAX_T)
		*(intmax_t *)ptr = char_written;
	else if (*flag & SIZE_T)
		*(size_t *)ptr = char_written;
	else
		*(int *)ptr = char_written;
}
