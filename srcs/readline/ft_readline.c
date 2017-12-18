/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/12 19:28:03 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"


void priint(int *a, int s)
{
	for(int i = 0; i < s; i++)
		printf("(%d)", a[i]);
}
void		ft_reprint_line(char *line, t_cursor *cursor)
{
	int		restore;
	
	restore = (*cursor).col;
	if_msc_keypad(HOME_KEY, cursor);
	while ((*cursor).col_end --> (*cursor).col_start)
		tputs(DELETE_CHAR, 1, ft_puti);
	ft_putstr_fd(line, STDIN_FILENO);
	(*cursor).col = restore;
	tputs(tgoto(CH_CURSOR_COL, 0, restore), 1, ft_puti);
	(*cursor).col_end += ft_strlen(line) + 1;
}

int			print(char **line, t_cursor *cursor, char input)
{
	int		pos;
	int		i;

	i = 0;
	pos = (*cursor).col - (*cursor).col_start;
	if (ft_strichar(line, pos, input))
	{
		ft_log("Insuficient memory for inserting a character.", 1);
		return (RET_ERR);
	}
	(*cursor).col++;
	(*cursor).col_end++;
	ft_reprint_line(*line, cursor);
	return (RET_OK);
}
static int	handle_input(char *input, t_chain **history, t_cursor *cursor);

char			*ft_readline(void)
{
	t_chain		*line;
	t_chain		*history;
	t_cursor	cursor;
	char		key[10];

	history = ft_init_history();
line = ft_chainnew(NULL);

	cursor.col_start = ft_strlen(PROMPT);
	cursor.col = cursor.col_start;
	cursor.col_end = cursor.col;

//	find();
	init_terminal_data();
	tty_enable_raw();

	tputs(tgetstr("ks", 0), 1, ft_puti);
	ft_bzero(key, 10);
	ft_putstrstr("\n\r", PROMPT);
	while (read(STDIN_FILENO, &key, 9))
	{
		if (ft_isprint(key[0]) || key[0] == '\r')
		{
			if (handle_input(key, &line, &cursor))
				break;
		}
		else
		{
			if (arrows(key, &cursor, &line, history) == DONE)
				;
			else
				detect_escape(key, &cursor, &line);
		}
		ft_strclr(key);
	}

ft_putstrstr("\n\r", line->value);
	if (line->value)
		ft_update_history(line->value);
ft_chainpurge(&history);
	tputs(tgetstr("ke", 0), 1, ft_puti);
	tty_disable_raw();
	return (NULL);
}

static int	handle_input(char *input, t_chain **history, t_cursor *cursor)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\r')
		{
			if (ft_lastchar((*history)->value) == '\\')
			{
				if (ft_strdchar(&((*history)->value), (*cursor).col - (*cursor).col_start - 1))
				{
					ft_log("error when delete the'\\'", 1);
					return (1);
				}
				(*cursor).col--;
				(*cursor).col_end--;
			}
			else
				return (-1);
		}
		else if (ft_isprint(input[i]))
			if (print(&((*history)->value), cursor, input[i]))
				return (1);
		++i;
	}
	return (0);
}
