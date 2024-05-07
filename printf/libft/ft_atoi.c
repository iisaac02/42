/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:13:14 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/12 17:58:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Elimina los espacios
//Multiplica los signos
//Si es un numero lo multiplica por 10 y le suma el numero
//Si no es un numero devuelve el numero multiplicado por el signo

#include "libft.h"
//#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	a;

	i = 0;
	n = 1;
	a = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	return (a * n);
}
/*
int	main(void)
{
	char	*str;
 	str = "  ---+--+1234ab567";

 	printf("%d",ft_atoi(str));
 	return (0);
}*/