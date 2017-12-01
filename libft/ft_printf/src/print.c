/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:01:41 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 15:29:45 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putc(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	padding_right(int flag, int width[2], char *s)
{
	int		char_written;
	int		len;

	char_written = 0;
	len = ft_len(s);
	if (flag & SHOW_SIGN)
	{
		char_written += ft_putc(*s++);
		width[1]++;
	}
	while (width[1]-- > len && (flag & ZERO_FLAG))
	{
		char_written += ft_putc('0');
		width[0]--;
	}
	while (*s != 0)
		char_written += ft_putc(*s++);
	while (width[0]-- > len)
		char_written += ft_putc(' ');
	return (char_written);
}

static int	pad_left_help(int width[2], int flag, char *s, int len_ch[2])
{
	int		char_written;

	char_written = 0;
	while (width[0] > len_ch[0])
	{
		if (s && ((((flag & SHOW_SIGN) || *s == '0') && width[1] > len_ch[0] \
						&& width[1] == width[0] && (flag & ZERO_FLAG)) || \
					((s[1] == 'x' || s[1] == 'X') && width[1] == width[0] - 2)))
		{
			char_written += ft_putc(*s++);
			if (*s == 'x' || *s == 'X')
			{
				char_written += ft_putc(*s++);
				if (width[1] == width[0] - 2)
					width[0] -= 2;
				else if (width[1] == width[0])
					len_ch[0] -= 2;
			}
		}
		char_written += ft_putc((width[0]-- > width[1]) ? ' ' : len_ch[1]);
	}
	while (s && *s)
		char_written += ft_putc(*s++);
	return (char_written);
}

static int	padding_left(int flag, int width[2], char *s)
{
	int		char_written;
	int		len_outchar[2];

	char_written = 0;
	len_outchar[0] = ft_len(s);
	len_outchar[1] = ((flag & ZERO_FLAG) && s) ? '0' : ' ';
	if (flag & ZERO_FLAG)
	{
		if (width[1] > width[0] && width[1] > len_outchar[0])
		{
			if (flag & SHOW_SIGN)
				width[1]++;
			width[0] = width[1];
		}
		else if (!width[1] && (!(flag & MAX_PRINT)))
		{
			if (flag & ALT_FORM)
				width[0] -= 2;
			width[1] = width[0];
		}
		else if (flag & SHOW_SIGN)
			width[1]++;
	}
	return (pad_left_help(width, flag, s, len_outchar));
}

int			ft_prints(char **s, int flag, int width[2])
{
	int		char_written;

	char_written = 0;
	if (flag & PAD_RIGHT)
		char_written = padding_right(flag, width, *s);
	else
		char_written = padding_left(flag, width, *s);
	if (!(flag & STRING_FLAG))
		free(*s);
	s = NULL;
	return (char_written);
}
