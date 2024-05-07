/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:37:52 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:10:02 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprueba si es un número

#include "libft.h"
//#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int	main(void)
{
	char	ch;

	printf("Introduce un carácter: ");
	scanf("%c", &ch);

	if (ft_isdigit(ch)) {
		printf("Es un número.\n");
	} else {
		printf("No es un número.\n");
	}
	return (0);
}*/