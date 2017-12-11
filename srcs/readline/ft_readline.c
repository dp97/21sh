/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 17:55:28 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"
#include "input_stream.h"

void			ft_purge_cursor(t_cursor **cursor)
{
	t_cursor	*tmp;

	while ((*cursor)->prev)
		*cursor = (*cursor)->prev;
	while (*cursor)
	{
		tmp = *cursor;
		*cursor = (*cursor)->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(*cursor);
	}
}

void priint(int *a, int s)
{
	for(int i = 0; i < s; i++)
		printf("(%d)", a[i]);
}

int			calc_pos(t_cursor *cursor)
{
	t_cursor	*tmp;
	int		pos;
	
	pos = cursor->col - cursor->col_start;
	tmp = cursor->prev;
	while (tmp)
	{
		pos += tmp->col_end - tmp->col_start;
		tmp = tmp->prev;
	}
	return (pos);
}

int			calc_pos_relative(t_cursor *cursor, int to)
{
	t_cursor	*tmp;
	int			pos;

	tmp = cursor;
	pos = to - tmp->col_start;
	tmp = tmp->prev;
	while (tmp)
	{
		pos += tmp->col_end - tmp->col_start;
		tmp = tmp->prev;
	}
	return (pos);
}

int			print(t_cmds **history, t_cursor **cursor, char input)
{
	int		pos;
	int		i;

	i = 0;
	pos = calc_pos(*cursor);
	if (ft_strichar(&((*history)->value), pos++, input))
	{
		ft_log("Insuficient memory for inserting a character.", 1);
		return (1);
	}
	ft_insert(input, cursor);
	return (0);
}
static int	handle_input(char *input, t_cmds **history, t_cursor **cursor);

char			*ft_readline(void)
{
	t_cmds		*history;
	t_cursor	*cursor;
	char		*in_memory;
	char		key[10];

	in_memory = NULL;
	history = ft_init_history();

	if (ft_cmdprepend(&history, ft_cmdnew(NULL)))
	{
		ft_log("Failed to initiate 'line'.", 1);
		return (NULL);
	}
if ((cursor = (t_cursor *)malloc(sizeof(t_cursor))) == NULL)
{
	ft_log("Failed to initiate 'cursor'.", 1);
	return (NULL);
}
	cursor->prev = NULL;
	cursor->next = NULL;
	cursor->col_start = ft_strlen(PROMPT);
	cursor->col = cursor->col_start;
	cursor->col_end = cursor->col;

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
			if (handle_input(key, &history, &cursor))
				break;
		}
		else
		{
			detect_ctrl(key, &cursor, &history);
			if_copy_paste(key, &cursor, &history, &in_memory);
		}
		ft_strclr(key);

	}

ft_putstrstr("\n\r", history->value);
	if (history->value)
		ft_update_history(history->value);
	ft_purgecmds(&history);
	ft_purge_cursor(&cursor);
	ft_strdel(&in_memory);
	tputs(tgetstr("ke", 0), 1, ft_puti);
	tty_disable_raw();
	return (NULL);
}

static int	handle_input(char *input, t_cmds **history, t_cursor **cursor)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\r')
		{
			if (ft_lastchar((*history)->value) == '\\')
			{
				if (ft_strdchar(&((*history)->value), calc_pos(*cursor) - 1))
				{
					ft_log("error when delete the'\\'", 1);
					return (1);
				}
				(*cursor)->col--;
				(*cursor)->col_end--;
				if (((*cursor)->next = (t_cursor *)malloc(sizeof(t_cursor))) == NULL)
				{
					ft_log("Failed to initiate 'cursor'.", 1);
					return (1);
				}
				(*cursor)->next->prev = *cursor;
				(*cursor) = (*cursor)->next;
				(*cursor)->next = NULL;

				(*cursor)->col_start = 2;
				(*cursor)->col = 2;
				(*cursor)->col_end = 2;
				ft_putstr("\n\r> ");
			}
			else
				return (-1);
		}
		else if (ft_isprint(input[i]))
			if (print(history, cursor, input[i]))
				return (1);
		++i;
	}
	return (0);
}
