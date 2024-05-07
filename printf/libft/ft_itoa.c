/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:47:54 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/10 11:37:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Pasa los números a positivo
//Va leyendo el string de atrás hacia delante
//Divide el número entre 10 hasta que dé 0
//Cuenta el número de dígitos de dentro de un string

#include "libft.h"
//#include <stdio.h>

int	count_number(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n /= 10;
			i++;
		}
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_setchr(char *res, int n, int i)
{
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = count_number(n);
	res = (char *)malloc((count_number(n) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		if (n == -2147483648)
		{
			res[i] = '8';
			n /= 10;
			i--;
		}
		n = -n;
	}
	ft_setchr(res, n, i);
	return (res);
}
/*
int	main(void)
{
	printf ("%s", ft_itoa(-2147483648));
	return (0);
}*/