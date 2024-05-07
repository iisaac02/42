/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:55:28 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:20 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Devuelve la longitud de la cadena

//#include <stdio.h>
#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int main(void)
{
	char	str[] = "Hola mundo";
	int		lon = ft_strlen(str);
	
	printf("El string tiene: %d letras", lon);
	return (0);
}*/