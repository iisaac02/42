/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:49:22 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:15:28 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Convierte un carácter a mayúscula

//#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}
/*
int	main(void)
{
	char	ch = 'a';

	printf("Antes: %c\n", ch);
	printf("Después: %c\n", ft_toupper(ch));
	return (0);
}*/