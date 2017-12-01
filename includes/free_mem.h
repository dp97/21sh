/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 09:08:26 by dpetrov           #+#    #+#             */
/*   Updated: 2017/03/02 09:08:29 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MEM_H
# define FREE_MEM_H
# include "minishell.h"

void	free_1d(char **s);
void	free_2d(char **hopa);
void	free_the_chain(t_cmd *history, int size);
#endif
