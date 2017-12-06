/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:42:25 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 18:38:35 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "check.h"
#include "free_mem.h"

static int	check_if_good(t_cmd history[], int *position, int counter)
{
	if (*position == FIFO_SIZE)
	{
		*position = 0;
		free_1d(&history[*position].line);
	}
	history[*position].id = counter;
	capture_time(history[*position].time);
	if ((history[*position].line = ft_readline()) == NULL)
		return (1);
	if (ft_strcmp(history[*position].line, "") == 0)
	{
		free_1d(&history[*position].line);
		return (1);
	}
	return (0);
}

static int	execute_queue(t_cmd history[], char **env, int position)
{
	char	*temp;
	short	cmds;

	cmds = 0;
	while (history[position].line[cmds])
	{
		temp = check_line(history[position].line, &cmds);
		if (check_for_variables(&temp, env))
			return (1);
		if (!temp || \
				(history[position].tokens = ft_get_args(env, temp)) == NULL)
		{
			free_1d(&temp);
			return (1);
		}
		free_1d(&temp);
		if (ft_execute(history[position].tokens, env, history) == 0)
			return (-1);
		free_2d(history[position].tokens);
	}
	return (0);
}

void		ft_loop(char **env)
{
	t_cmd	history[FIFO_SIZE];
	int		position;
	int		counter;
	int		status;

	counter = 1;
	signal(SIGINT, sig_handler);
	position = 0;
	g_sig = 0;
	set_null_id(history);
	while (1)
	{
		if (g_sig != 2)
			ft_putstrstr("\n\r", PROMPT);
		g_sig = 0;
		if (check_if_good(history, &position, counter))
			continue;
		if ((status = execute_queue(history, env, position)) == 1)
			continue;
		else if (status == -1)
			break ;
		++position;
		++counter;
	}
	free_the_chain(history, counter);
}
