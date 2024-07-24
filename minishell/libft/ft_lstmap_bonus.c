/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:15 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/12 09:24:08 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;
	void	*result;

	newlist = 0;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		result = f(lst->content);
		newnode = ft_lstnew(result);
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			del(result);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
