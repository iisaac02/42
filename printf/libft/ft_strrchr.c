/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:59:47 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:15:15 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Busca la última ocurrencia de c en la cadena s

//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*n;

	n = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			n = (char *)s;
		s++;
	}
	if (*s == (char)c)
		n = (char *)s;
	return (n);
}
/*
int	main(void)
{
	char	str[] = "Hola Mundo!";
	char	*ptr = "l";

	ptr = ft_strrchr(str, *ptr);
	printf("%s", ptr);

	return (0);
}*/