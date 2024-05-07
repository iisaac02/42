/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:02:20 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/07 13:03:18 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Elimina el contenido de un string

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		*p++ = 0;
	}
}
/*
int	main(void)
{
	char	str[10] = "Hola";

	printf("Antes: %s\n", str);
	ft_bzero(str, sizeof(str));
	printf("Después: %s\n", str);
	return (0);
}*/