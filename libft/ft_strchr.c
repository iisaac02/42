/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:55:23 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:38 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Busca la primera aparición de un carácter en un string
//Devuelve la posición del carácter en el string

//#include <stdio.h>
#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return (s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return (s);
	}
	return (NULL);
}
/*
int	main(void)
{
	char		*str = "Hola Mundo";
	int			ch = 'd';
	char		*result = ft_strchr(str, ch);

	if (result != NULL)
		printf("Carácter '%c' en la posición: %ld\n", ch, result - str);
	else
		printf("Carácter '%c' no encontrado\n", ch);
	return (0);
}*/