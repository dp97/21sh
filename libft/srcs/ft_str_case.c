/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 08:57:28 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/08 09:21:30 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	1 to UPPER || 0 to LOW
*/

char	*ft_str_case(char *s, int up_or_low)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (up_or_low)
			s[i] = ft_toupper(s[i]);
		else
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
