/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stream.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:51:55 by dpetrov           #+#    #+#             */
/*   Updated: 2017/12/07 19:42:25 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_stream.h"

t_cmds		*ft_cmdnew(char *value)
{
	t_cmds	*new;

	if ((new = (t_cmds *)malloc(sizeof(t_cmds))) == NULL)
		return (NULL);
	if (value)
	{
		if ((new->value = (char *)malloc(sizeof(value))) == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_strcpy(new->value, value);
	}
	else
		new->value = NULL;
	new->next = NULL;
	return (new);
}

void		ft_cmddel(t_cmds **head, int this)
{
	t_cmds	*prev;
	t_cmds	*todel;

	if (head == NULL)
		return ;
	prev = (*head)->next;
	todel = (*head)->next;
	if (this <= 0)
	{
		(*head)->next = todel->next;
		if (todel == NULL)
			return ;
		if (todel->value)
			free(todel->value);
		free(todel);
		return ;
	}
	while (this-- && todel)
	{
		prev = todel;
		todel = todel->next;
	}
	if (todel == NULL)
		return ;
	prev->next = todel->next;
	if (todel->value)
		free(todel->value);
	free(todel);
}

void		ft_purgecmds(t_cmds **head)
{
	t_cmds	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		if (tmp->value)
			free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
}

int			ft_cmdadd(t_cmds **head, t_cmds *new)
{
	t_cmds	*tmp;

	if (new == NULL)
		return (1);
	else if (*head == NULL)
	{
		*head = new;
		return (0);
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
