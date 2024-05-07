/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:32:40 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/09 13:42:43 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Elimina y libera el nodo ’lst’ dado y todos losconsecutivos de ese nodo,
utilizando la función ’del’ y free */

#include "libft.h"
//#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst && *lst && del)
	{
		current = *lst;
		while (current)
		{
			next = current -> next;
			del(current -> content);
			free(current);
			current = next;
		}
		*lst = NULL;
	}
}
