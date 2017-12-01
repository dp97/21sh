/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:07:02 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/03 13:52:58 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"
# include <dirent.h>

int	parser(char **arg, char **env, char *token, int *count);
int	handle_quotes(char **arg, char *token, int *pos);
int	find_match(char *s1, char *s2);
int	handle_home_dir(char **arg, char **env, char *token, int *pos);
int	ft_wildcard(char **arg, char *token, int *pos);
#endif
