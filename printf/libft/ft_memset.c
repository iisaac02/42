/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:59:31 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:11:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Sustituye los primeros n bytes de un string por un carácter

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
	{
		*p++ = (c);
	}
	return (s);
}
/*
int	main(void)
{
	char	str[50] = "Hola Mundo!";

	printf("Antes memset: %s\n", str);
	ft_memset(str, '$', 7);
	printf("Después memset: %s\n", str);

	return (0);
}*/