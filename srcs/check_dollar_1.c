/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 08:59:18 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/02 14:34:04 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

static int	handle_brace(char *token, int *i, int *size)
{
	*i += 1;
	*size -= 1;
	while (token[*i])
	{
		if (token[*i] == '}')
			return (0);
		*i += 1;
		*size += 1;
	}
	return (1);
}

char		*check_line(char *line, short *pos)
{
	int		i;
	char	*ret;

	i = *pos;
	ret = NULL;
	while (line[*pos])
	{
		if (line[*pos] == ';')
		{
			if (*pos && line[*pos - 1] != ';')
				break ;
			i = *pos + 1;
		}
		*pos += 1;
	}
	ret = ft_strndup(&line[i], *pos - i);
	ret[*pos] = '\0';
	if (line[*pos])
		*pos += 1;
	return (ret);
}

static int	get_var_size(char **token, int *i, int *size)
{
	if ((*token)[*i + 1] == '{')
	{
		if (handle_brace(*token, i, size))
			return (check_error(NULL, "Missing }."));
	}
	else
		while ((*token)[++(*i)] \
				&& (ft_isdigit((*token)[*i]) || ft_isalpha((*token)[*i])))
			*size += 1;
	return (0);
}

static int	putting_the_var(char **env, char **token, int i, int size)
{
	char	*var_content;
	char	*var_name;
	short	brace;

	var_name = strndup(&(*token)[i - size], size);
	var_name[size] = '\0';
	if ((var_content = ft_getenv(var_name, env)) == NULL)
	{
		free(var_name);
		return (check_error(var_name, ": Undefined variable."));
	}
	free(var_name);
	if ((brace = ((*token)[i - size - 1] == '{') ? 1 : 0))
		size += 1;
	ft_extend(token, var_content, i - size - 1, (brace) ? ++size : size);
	return (0);
}

int			check_for_variables(char **token, char **env)
{
	int		i;
	int		size;

	i = 0;
	while ((*token)[i])
	{
		if ((*token)[i] == '$')
		{
			size = 0;
			if (get_var_size(token, &i, &size))
				return (1);
			if (size == 0)
				continue;
			if ((*token)[i] && (*token)[i - 1] == '$')
				return (check_error(NULL, "Illegal variable name."));
			if (putting_the_var(env, token, i, size))
				return (1);
		}
		++i;
	}
	return (0);
}
