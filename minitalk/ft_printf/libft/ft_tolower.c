/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:51:50 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:15:23 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Convierte un carácter a minúscula

//#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
/*
int	main(void)
{
	char	ch = 'A';

	printf("Antes: %c\n", ch);
	printf("Después: %c\n", ft_tolower(ch));
	return (0);
}*/