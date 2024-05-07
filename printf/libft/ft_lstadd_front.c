/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:31:21 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/09 13:18:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Añade al nodo new al principio de una lista

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	last = new;
	while (last -> next)
		last = last -> next;
	last -> next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *lstnew;
	t_list *lstadd;

	lstnew = ft_lstnew("hola");
	lstadd = ft_lstnew("hola mundo");
	ft_lstadd_front(&lstnew, lstadd);
	while (lstnew != NULL)
	{
		printf("%s\n", lstnew -> content);
		lstnew = lstnew -> next;
	}
	return (0);
}*/