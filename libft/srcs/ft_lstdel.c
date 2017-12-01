/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 16:49:33 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/21 16:57:06 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nextl;

	lst = *alst;
	while (lst)
	{
		nextl = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nextl;
	}
	*alst = NULL;
}
