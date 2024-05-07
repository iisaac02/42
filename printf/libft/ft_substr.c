/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:22:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/01 21:06:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Copia desde el carácter que se indique
//Copia el número de carácteres que se indique
//Incluir todas las funciones al compilar

#include "libft.h"
#include <stdio.h>

size_t	ft_max(size_t len, size_t max)
{
	if (len > max)
		len = max;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		start2;
	size_t		max;

	if (start > (unsigned int)ft_strlen(s))
		max = 0;
	else
		max = ft_strlen(s) - start;
	len = (ft_max(len, max));
	start2 = (int)start;
	if (!s)
		return (NULL);
	if (start2 > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start2;
	j = 0;
	while (s[i] && j < len && start2 < (size_t)ft_strlen(s))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*src = "Hola Mundo!";
	int		start = 2;
	int		len = 6;

	printf("%s\n", ft_substr(src, start, len));
	return (0);
}*/