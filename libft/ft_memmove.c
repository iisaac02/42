/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:08:03 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/07 13:43:18 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia n bytes de src a dest

//#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	char	*ptr2;

	ptr = (char *)dest;
	ptr2 = (char *)src;
	if (!dest && !src && n > 0)
		return (dest);
	if (ptr2 < ptr)
	{
		while (n--)
			ptr[n] = ptr2[n];
	}
	else
		ft_memcpy(ptr, ptr2, n);
	return (dest);
}
/*
int main(void)
{
	char	src[] = "Hola Mundo!";
	char	dest[20];

	ft_memmove(dest, src, strlen(src) + 1);

	printf("Copied string: %s\n", dest);

	return (0);
}*/
