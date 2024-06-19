/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:27:10 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:27:10 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freelst(t_list *lst, void (*del)(void *))
{
	t_list			*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (del)
			del(tmp->content);
		free(tmp);
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new;
	t_list			*node;

	if (!lst)
		return (0);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new->content = f(lst->content);
	new->next = 0;
	node = new;
	lst = lst->next;
	while (lst)
	{
		node->next = (t_list *)malloc(sizeof(t_list));
		if (node->next == 0)
			return (ft_freelst(new, del));
		node->next->content = f(lst->content);
		node->next->next = 0;
		node = node->next;
		lst = lst->next;
	}
	return (new);
}
