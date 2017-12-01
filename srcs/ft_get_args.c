/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:57:42 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 17:32:21 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "free_mem.h"
#include "parser.h"

static void	ft_cases(char **line, int *size, int *i)
{
	if ((*line)[*i] && (*line)[*i] == '\'')
	{
		*size += 1;
		while ((*line)[++(*i)] && (*line)[*i] != '\'')
			*size += 1;
	}
	else if ((*line)[*i] && (*line)[*i] == '\"')
	{
		*size += 1;
		while ((*line)[++(*i)] && (*line)[*i] != '\"')
			*size += 1;
	}
	else
	{
		*i += 1;
		*size += 1;
	}
}

static int	ft_len_of_next_token(char **line)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while ((*line)[i])
	{
		while ((*line)[i] && (*line)[i] != '\t' \
				&& (*line)[i] != ' ' && (*line)[i] != '\n')
			ft_cases(line, &size, &i);
		if (size)
			return (size);
		if ((*line)[i])
			(*line)++;
	}
	return (-1);
}

char		**not_enough_mem(char ***tokens, char **token)
{
	free_1d(token);
	free(*tokens);
	return (NULL);
}

char		**ft_get_args(char **env, char *line)
{
	int		len;
	int		position;
	char	*token;
	char	**tokens;
	int		status;

	position = 0;
	if ((tokens = (char **)malloc(sizeof(char *) * TOKENS)) == NULL)
	{
		ft_error("malloc: Not enough space.");
		return (NULL);
	}
	while (*line)
	{
		if ((len = ft_len_of_next_token(&line)) == -1)
			break ;
		token = ft_strndup(line, len);
		token[len] = '\0';
		if ((status = parser(tokens, env, token, &position)) != 0)
			return (not_enough_mem(&tokens, &token));
		free_1d(&token);
		line += len;
	}
	tokens[position] = NULL;
	return (tokens);
}
