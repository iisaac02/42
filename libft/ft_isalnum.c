/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:43:10 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:09:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprueba si es alfanumerico

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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

	if (ft_isalnum(ch)) {
		printf("%c es alfanumérico.\n", ch);
	} else {
		printf("%c no es alfanumérico.\n", ch);
	}
	return (0);
}*/