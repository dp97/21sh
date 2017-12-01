/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:27:42 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/31 09:39:42 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dp_strcmp(char *s1, char *s2, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (*s1++ == *s2++ && *s2)
			i++;
		else
			return (-1);
	}
	return (i);
}

int		dp_check_color(const char *s, int *flag)
{
	char	*p;
	short	n;

	p = (char *)s;
	if ((n = dp_strcmp("{red}", p, 5)) == 5)
		ft_printf(COLOR_RED);
	else if ((n = dp_strcmp("{green}", p, 7)) == 7)
		ft_printf(COLOR_GREEN);
	else if ((n = dp_strcmp("{yellow}", p, 8)) == 8)
		ft_printf(COLOR_YELLOW);
	else if ((n = dp_strcmp("{blue}", p, 6)) == 6)
		ft_printf(COLOR_BLUE);
	else if ((n = dp_strcmp("{magenta}", p, 9)) == 9)
		ft_printf(COLOR_MAGENTA);
	else if ((n = dp_strcmp("{cyan}", p, 6)) == 6)
		ft_printf(COLOR_CYAN);
	else if ((n = dp_strcmp("{eoc}", p, 5)) == 5)
	{
		ft_printf(COLOR_RESET);
		return (n);
	}
	else
		return (0);
	*flag |= ACTIVE_COLOR;
	return (n);
}
