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
#include "builtins.h"

int		main(int argc, char **argv, char **env)
{
	char	*line;
	t_token	*tokens;
	t_cmd	*cmds;
	int		status;
	(void)argc;
	(void)argv;
	setup_signals();
	while(1)
	{
//ft_setenv("HELLO", "testing...",1);
//ft_putstr(getenv("HELLO"));
		line = ft_readline();
		ft_putchar('\n');
		if (line == NULL)
		{
			ft_strdel(&line);
			continue ;
		}

		tokens = tokening(line);
		ft_strdel(&line);

		cmds = parser(tokens);
		if (cmds == NULL)
			continue ;
		ft_deltokens(&tokens);
		
		status = execute(cmds, env);
		purge_cmd(cmds);

		if (status == EXIT)
		{
			ft_putstr("exit\n");
			break ;
		}
	}
	return (0);
}
