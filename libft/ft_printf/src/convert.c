/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:23:30 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/30 11:17:56 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert(unsigned long long v, char *ans, unsigned int b, int *p)
{
	char	num[16];

	dp_strcpy(num, "0123456789ABCDEF");
	if (b <= v)
		convert(v / b, ans, b, p);
	ans[(*p)++] = num[v % b];
}

void		ft_itoa_base(char *buf, unsigned long long value, \
		unsigned int base, int up_low)
{
	int		p;

	p = 0;
	convert(value, buf, base, &p);
	buf[p] = '\0';
	(up_low) ? buf : ft_str_case(buf, 0);
}
