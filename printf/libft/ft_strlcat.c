/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:21:32 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:58 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concatena dos strings

#include "libft.h"
//#include <stdio.h>

int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	total_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	total_len = dst_len + src_len;
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (total_len);
}
/*
int	main(void)
{
	char		dst[20] = "Hola";
	char		*src = "Mundo";

	printf("%s %s\n", dst, src);
	return (0);
}*/