/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:12:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/15 09:35:35 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

long int	static	ft_baseexponente(long int base, size_t exp)
{
	long int	nbr;

	if (exp == 0)
		return (1);
	nbr = base;
	while (--exp)
		nbr *= base;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	digitos;

	digitos = 1;
	while (n / ft_baseexponente(10, digitos))
		digitos++;
	nbr = (char *)ft_calloc(digitos + 1, sizeof(char));
	if (!nbr)
		return (0);
	while (--digitos)
	{
		nbr[digitos] = (char)((n % 10) + '0');
		n /= 10;
	}
	nbr[digitos] = (char)((n % 10) + '0');
	return (nbr);
}
