/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:04:17 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:11:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia n bytes de src a dest

//#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p;
	const unsigned char	*s;

	p = dest;
	s = src;
	if (!dest && !src && n > 0)
		return (dest);
	while (n-- > 0)
	{
		*p++ = *s++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "Campus42";
	char	dest[] = "";
	int		n;

	n = 4;
	printf("%s", ft_memcpy(dest, src, n));
	return (0);
}*/