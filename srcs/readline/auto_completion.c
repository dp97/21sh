/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 11:24:20 by dpetrov           #+#    #+#             */
/*   Updated: 2018/04/18 18:06:51 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_readline.h"

void				insert_completion(char *name, int from, t_cursor *cursor, t_chain **line)
{
	int				pos;

	pos = ft_posinstr(*cursor);
	while ((*line)->value[pos] != ' ' && (*line)->value[pos++] != '\0')
		(*cursor).col++;
	while (name[from] != '\0')
		ft_insert_char(&((*line)->value), cursor, name[from++]);
}

/*
 * Extract the word(delimited by space and tab and where cursor is), 
 * in order to search matching filenames in directory.
*/
char				*setup_name(int pos, char *line)
{
	int				i;
	char			*name;

	if (!line)
		return (NULL);
	if (line[pos] != ' ' || (line[pos] == ' ' && pos > 0 && line[pos - 1] != ' '))
	{
		while (pos > 0 && line[--pos] != ' ')
			;
		if (line[pos] == ' ')
			pos++;
	}
	else if (line[pos] == ' ')
		return (NULL);
	while (line[pos] != ' ')
	{
		if (line[pos] == '\0')
			break;
		pos++;
		i++;
	}
	name = ft_strndup(&line[pos - i], i);
	return (name);
}

/*
** t_cursor is the position of cursor.
** t_chain is lines readed drom input.
*/
void				auto_completion(t_cursor *cursor, t_chain **line)
{
	DIR				*dirp;
	char			*name;
	struct dirent	*dir;
	short			matches;

	matches = 0;
	if ((dirp = opendir(getenv("PWD"))) == NULL)
	{
		perror("cannot open directory");
		return ;
	}
	name = setup_name((*cursor).col - (*cursor).col_start, (*line)->value);
	while ((dir = readdir(dirp)) != NULL)
	{
		if (0 == ft_strncmp(dir->d_name, name, ft_strlen(name)))
		{
			insert_completion(dir->d_name, ft_strlen(name), cursor, line);
			break ;
		}
	}
	ft_strdel(&name);
}
