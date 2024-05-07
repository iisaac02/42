/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:22:27 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:18:10 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reserva memoria y la inicializa a 0

#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t cont, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(cont * size);
	if (ptr != NULL)
	{
		i = 0;
		while (i < cont * size)
		{
			((char *)ptr)[i] = 0;
			i++;
		}
	}
	return (ptr);
}
/*
int	main(void)
{
	int		*ptr;
	int		i;
	int		n;

	n = 5;
	ptr = (int *)ft_calloc(n, sizeof(int));
	if (ptr != NULL)
	{
		i = 0;
		while (i < n)
		{
			printf("%d\n", ptr[i]);
			i++;
		}
	}
	return (0);
}*/