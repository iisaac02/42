/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:25:03 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/07 13:13:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Busca un carácter en una cadena
//Devuelve un puntero al carácter encontrado o NULL si no lo encuentra
//Escribe a partir de la posición del puntero

//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Hola Mundo";
	char	ch = 'l';
	size_t	n = 4;

	printf("%s\n", ft_memchr(str, ch, n));
	return (0);
}*/