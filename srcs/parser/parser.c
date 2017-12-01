/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:05:12 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 17:07:35 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int					parser(char **arg, char **env, char *token, int *pos)
{
	int				len;

	len = 0;
	if (ft_strchr(token, '"') || ft_strchr(token, '\''))
		return (handle_quotes(arg, token, pos));
	if (token[0] == '~' && *pos == 1)
		return (handle_home_dir(arg, env, token, pos));
	if (ft_strchr(token, '*') == NULL && ft_strchr(token, '?') == NULL)
	{
		if (!pos)
			return (1);
		if ((arg[*pos] = ft_strdup(token)) == NULL)
			return (ft_error("malloc: Not enough space."));
		*pos += 1;
		return (0);
	}
	if ((len = ft_wildcard(arg, token, pos)) == -1)
		return (-1);
	return (0);
}
