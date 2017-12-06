/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:52:07 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/06 20:07:57 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void printt(t_list *line)
{
	while (line)
	{
		ft_putstrstr(line->content, "\n\r");
		line = line->next;
	}
}

char		*ft_readline(void)
{
	t_cupos	cursor;
	t_list	*head;
	t_list	*line;
	char	key[5];

	/*line = NULL;
	if ((get_next_line(STDIN_FILENO, &line)) < 0)
		ft_error("error geting line Sir !");
		ft_putstr_fd(line, STDIN_FILENO);*/
	cursor.col_start = ft_strlen(PROMPT);
	cursor.col = cursor.col_start;
	cursor.col_end = cursor.col;
	head = ft_lstnew(PROMPT, sizeof(PROMPT));
	line = head;
	tputs(tgetstr("ks", 0), 1, ft_puti);
	while (read(STDIN_FILENO, &key, 5) && key[0] != '\r')
	{
		printf("(%d-%d-%d-%d-%d)", key[0], key[1], key[2], key[3], key[4]);
	//printf("(%s)", key);
		if (ft_isprint(key[0]))
		{
			//printf("%d ('%c')\n", key, key);
			//line = ft_strapnd(line, key);
			ft_lstadd(&line, ft_lstnew(key, ft_strlen(key) * 4));
			ft_insert(key[0]);
			cursor.col++;
			cursor.col_end++;
		}
		else
			detect_ctrl(key, &cursor);
		ft_bzero(key, 5);
	}
	printt(head);
	return (NULL);
}


