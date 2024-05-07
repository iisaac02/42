/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:57:05 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/13 16:14:18 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int x, int *length, char x_or_x)
{
	char	string[25];
	char	*base;
	int		i;

	if (x_or_x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar('0', length);
		return ;
	}
	while (x != 0)
	{
		string[i] = base [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar(string[i], length);
}
/*
int	main(void)
{
	unsigned int	num = 42;
	int				length = 0;

	printf("Número en hexadecimal:\n ");
	ft_puthex(num, &length, 'X');
	printf("\n");

	return (0);
}*/