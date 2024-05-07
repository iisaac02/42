/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:33:50 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:15:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Busca la primera ocurrencia de needle en haystack

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

char	*ft_strnstr(const char *hays, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;

	i = 0;
	j = 0;
	hay = (char *)hays;
	if (needle[0] == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		while (hay[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&hay[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	haystack[] = "Cursus";
	char	needle[] = "r";
	size_t	lon = 4;

	printf("%s\n", ft_strnstr(haystack, needle, lon));
	printf("%s\n", strnstr(haystack, needle, lon));
	return (0);
}*/