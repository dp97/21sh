/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_symbol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:24:11 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 13:57:57 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			handle_home_dir(char **arg, char **env, char *token, int *pos)
{
	char	*home_dir;
	int		home_len;
	int		token_len;

	if ((home_dir = ft_getenv("HOME", env)) == NULL)
		return (ft_error("HOME is not seted."));
	home_len = ft_strlen(home_dir);
	token_len = ft_strlen(token);
	if ((arg[*pos] = (char *)malloc(sizeof(char) * \
					(token_len + home_len))) == NULL)
		return (ft_error("malloc: Not enough space."));
	ft_memcpy(arg[*pos], home_dir, home_len);
	ft_memcpy(&arg[*pos][home_len], &token[1], token_len);
	*pos += 1;
	return (0);
}
