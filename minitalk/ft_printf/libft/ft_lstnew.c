/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:00:11 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/08 20:51:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Crea una nueva lista

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int	main(void)
{
	t_list	*func;

	func = ft_lstnew("hola");
	printf("%s\n", func -> content);
	return (0);
}*/