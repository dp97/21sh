/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:11:48 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/04 15:27:28 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free_mem.h"

static int	check_quotes(char **arg, char *token, int *i, int *count)
{
	if (token[*i] == '\'')
	{
		while (token[++(*i)] && token[*i] != '\'')
			(*arg)[(*count)++] = token[*i];
		if (token[*i] != '\'')
		{
			free_1d(arg);
			return (ft_error("Unmatched '."));
		}
	}
	else if (token[*i] == '\"')
	{
		while (token[++(*i)] && token[*i] != '\"')
			(*arg)[(*count)++] = token[*i];
		if (token[*i] != '\"')
		{
			free_1d(arg);
			return (ft_error("Unmatched \"."));
		}
	}
	else
		(*arg)[(*count)++] = token[*i];
	return (0);
}

int			handle_quotes(char **arg, char *token, int *pos)
{
	int		i;
	int		count;

	if ((arg[*pos] = (char *)malloc(sizeof(char) * ft_strlen(token))) == NULL)
		return (ft_error("malloc: Not enough space."));
	i = 0;
	count = 0;
	while (token[i])
	{
		if (check_quotes(&arg[*pos], token, &i, &count))
			return (1);
		if (token[i])
			++i;
	}
	arg[(*pos)++][count] = '\0';
	return (0);
}
