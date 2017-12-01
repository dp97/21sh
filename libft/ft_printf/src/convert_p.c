/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:25:53 by dpetrov           #+#    #+#             */
/*   Updated: 2017/01/03 10:38:45 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_p(char *buf, int *flag, unsigned long long value, short up_low)
{
	if (value == 0 && (*flag & MAX_PRINT))
	{
		dp_strcpy(buf, "0x");
		*flag ^= MAX_PRINT;
		return (1);
	}
	dp_strcpy(buf, "0x");
	ft_itoa_base(&buf[2], value, 16, up_low);
	return (1);
}
