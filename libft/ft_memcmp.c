/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:25:25 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:11:02 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compara dos strings

//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str[i] != str2[i])
		{
			return (str[i] - str2[i]);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "Hola";
	char	str2[] = "Adios";
	size_t	n = 3;

	printf("%d\n", ft_memcmp(str, str2, n));
	return (0);
}*/