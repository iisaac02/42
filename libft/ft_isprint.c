/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:50:51 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:10:07 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprueba si es un carácter imprimible

#include "libft.h"
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char	ch;

	printf("Introduce un carácter: ");
	scanf("%c", &ch);

	if (ft_isprint(ch))
		printf("Si es un carácter imprimible.\n");
	else
		printf("No es un carácter imprimible.\n");

	return (0);
}*/