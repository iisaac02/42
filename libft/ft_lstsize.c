/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:17:54 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/08 20:51:41 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Devuelve el número de elementos de una lista

#include "libft.h"
//#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*lst4;

	lst = ft_lstnew("hola");
	lst2 = ft_lstnew("adios");
	lst3 = ft_lstnew("buenos");
	lst4 = ft_lstnew("dias");
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst3, lst4);
	ft_lstadd_front(&lst, lst3);
	printf("%d\n", ft_lstsize(lst));
	return (0);
}*/