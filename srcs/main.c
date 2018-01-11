/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:17:14 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/08 12:33:43 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokening.h"
#include "ft_readline.h"
#include "execute.h"
#include "parser.h"

void printt(t_token *t)
{
	while (t)
	{
			printf("{%s} %d\n", t->value, t->type);
		t = t->next;
	}
}

int		main(int argc, char **argv, char **env)
{
	char	*line;
	t_token	*tokens;
	char	**cmds;
	int		code;
	(void)argc;
	(void)argv;
	while(1)
	{
		line = ft_readline();
		ft_putchar('\n');
		
		tokens = tokening(line);
		ft_strdel(&line);

		cmds = parser(tokens);
		ft_deltokens(&tokens);

		code = execute(cmds, env);

		if (code == EXIT)
		{
			ft_putstr("exit\n");
			break ;
		}
		//printt(tokening(line));
	}
	return (0);
}
