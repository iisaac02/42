/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:58:14 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/11 15:26:19 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while ((*lst) != NULL)
	{
		temp = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		*lst = temp;
	}
	(*lst) = NULL;
}
