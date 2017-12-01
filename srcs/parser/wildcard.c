/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:18:02 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/04 12:42:37 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free_mem.h"

int					find_match(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0' || *s2 == '\0')
		return (1);
	else if (*s1 == *s2)
		return (find_match(s1 + 1, s2 + 1));
	else if (*s2 == '*')
	{
		if (*++s2)
		{
			while (*s1 && *s2 != *s1)
				++s1;
			return (find_match(s1, s2));
		}
		else
			return (0);
	}
	else if (*s2 == '?')
		return (find_match(s1 + 1, s2 + 1));
	else
		return (1);
}

void				ft_sort(char **arg, int *pos, int len)
{
	char			*tmp;
	int				i;

	i = *pos - len;
	while (i < len)
	{
		if (ft_strcmp(arg[i], arg[i + 1]) > 0)
		{
			tmp = arg[i];
			arg[i] = arg[i + 1];
			arg[i + 1] = tmp;
			i = *pos - len;
		}
		else
			i++;
	}
}

static int			ft_set_path(char **path, char *token, char **card)
{
	int				i;
	int				path_len;

	i = 0;
	path_len = 0;
	while (token[i] && token[i] != '*')
	{
		if (token[i] == '/')
			path_len = (i == 0) ? 1 : i;
		++i;
	}
	if ((*path = (char *)malloc(sizeof(char) * path_len + 3)) == NULL)
		return (1);
	if (path_len > 1)
	{
		ft_strncpy((*path), token, path_len);
		(*path)[path_len] = '\0';
		*card = ft_strdup(&token[path_len + 1]);
	}
	else
	{
		ft_strcpy(*path, (path_len == 1) ? "/" : ".");
		*card = ft_strdup((path_len == 1) ? &token[1] : token);
	}
	return (0);
}

static int			ft_search_dir(DIR *dir, char **arg, char *w_card, int *pos)
{
	struct dirent	*file;
	int				len;

	len = 0;
	while ((file = readdir(dir)) != NULL)
	{
		if (file->d_name[0] == '.')
			continue;
		if (find_match(file->d_name, w_card) == 0)
		{
			if ((arg[*pos] = ft_strdup(file->d_name)) == NULL)
				return (ft_error("malloc: Not enough space.") - 2);
			*pos += 1;
			++len;
		}
	}
	return (len);
}

int					ft_wildcard(char **arg, char *token, int *pos)
{
	DIR				*dir;
	int				len;
	char			*path;
	char			*w_card;

	path = NULL;
	w_card = NULL;
	ft_set_path(&path, token, &w_card);
	if ((dir = opendir(path)) == NULL || ft_strchr(w_card, '/'))
	{
		free_1d(&path);
		free_1d(&w_card);
		return (check_error(token, ": No matches found.") - 2);
	}
	free_1d(&path);
	if ((len = ft_search_dir(dir, arg, w_card, pos)) == -1)
		return (-1);
	closedir(dir);
	free_1d(&w_card);
	if (len == 0)
		return (check_error(token, ": No matches found.") - 2);
	ft_sort(arg, pos, len);
	return (len);
}
