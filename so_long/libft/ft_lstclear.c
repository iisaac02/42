/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:49 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:26:49 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list			*tmp;
	t_list			*node;

	if (!*lst)
		return ;
	node = *lst;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (del)
			del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
