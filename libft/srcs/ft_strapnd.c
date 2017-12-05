/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strapnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:43:01 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/05 17:33:01 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes a string and a character.
**	Returns a new string and character appended to it.
**	if s is NULL, then a new string with c is returned.
*/
char		*ft_strapnd(char *s, char c)
{
	char	*new;
	char	ch[2];
	int		len;

	ch[0] = c;
	ch[1] = '\0';
	if (s == NULL)
		new = ft_strdup(ch);
	else
	{
		len = ft_strlen(s);
		if ((new = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_strcpy(new, s);
		new[len] = c;
		new[len + 1] = '\0';
		//free(*s);
	}
	return (new);
}
