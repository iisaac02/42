/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:44:29 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:09:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprueba si es un carácter ASCII

#include "libft.h"
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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

	if (ft_isascii(ch)) {
		printf("Es un carácter ASCII.\n");
	} else {
		printf("No es un carácter ASCII.\n");
	}
	return (0);
}*/