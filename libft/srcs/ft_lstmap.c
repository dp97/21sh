/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 17:10:21 by dpetrov           #+#    #+#             */
/*   Updated: 2016/10/21 17:31:23 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*root;

	while (lst)
	{
		if ((root = (t_list *)malloc(sizeof((*f)(lst)))) == NULL)
			return (NULL);
		root = (*f)(lst);
		root->next = ft_lstmap(lst->next, (*f));
		return (root);
	}
	return (NULL);
}
