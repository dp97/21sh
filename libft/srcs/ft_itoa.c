/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 23:03:16 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/18 14:25:22 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		if_neg(int *a, int *b, int *c)
{
	if (*a < 0)
	{
		*a *= -1;
		*b = 1;
		*c += 1;
	}
}

char			*ft_itoa(int n)
{
	char	*s;
	int		sign;
	int		tmp;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	len = 1;
	sign = 0;
	if_neg(&n, &sign, &len);
	while (tmp /= 10)
		len++;
	if ((s = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		s[0] = '-';
	return (s);
}
