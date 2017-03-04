/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho <apinho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:13:29 by apinho            #+#    #+#             */
/*   Updated: 2017/02/24 18:34:19 by apinho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*stock;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if ((new_lst = ft_lstnew(tmp->content, tmp->content_size)))
	{
		stock = new_lst;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(stock->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			stock = stock->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
