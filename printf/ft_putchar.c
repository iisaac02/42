/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:59:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/02/02 14:11:24 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *length)
{
	if (write(1, &c, 1) < 0)
		*length = -1;
	(*length)++;
}
/*
int	main(void)
{
	int length = 0;
	char character = 'A';

	ft_putchar(character, &length);
	printf ("\n");
	printf("Longitud: %d\n", length);

	return (0);
}*/