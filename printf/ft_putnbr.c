/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:59:13 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/01/31 11:52:51 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int number, int *length)
{
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (number < 0)
	{
		ft_putchar('-', length);
		ft_putnbr(number * -1, length);
	}
	else
	{
		if (number > 9)
			ft_putnbr(number / 10, length);
		ft_putchar(number % 10 + '0', length);
	}
}
/*
int	main(void)
{
	int	number = 42;
	int	length = 0;

	ft_putnbr(number, &length);
	printf("\n");

	return (0);
}*/