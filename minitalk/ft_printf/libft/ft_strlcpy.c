/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:10:23 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/09 14:36:33 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia la cadena src en la cadena dest

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;

	a = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (a);
}
/*
int	main(void)
{
	char	src[] = "Campus42";
	char	dest[] = "";

	printf("%d | %s", ft_strlcpy(dest, src, 9), dest);
}*/