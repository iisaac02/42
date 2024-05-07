/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:56:20 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/18 18:23:17 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int u, int *length)
{
	if (u >= 10)
		ft_putunsigned(u / 10, length);
	if (*length == -1)
		return ;
	ft_putchar(u % 10 + '0', length);
}
/*
int	main(void)
{
	unsigned int	num = -12345;
	int				length = 0;

	ft_putunsigned(num, &length);
	printf("\n");

	return (0);
}*/