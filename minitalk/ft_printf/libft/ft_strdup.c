/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:14:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/01 19:09:53 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Duplica un string

//#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*src;
	char	*dest;

	src = "Hola Mundo!";
	dest = ft_strdup(src);
	printf("String copiado: %s\n", dest);
	return (0);
}*/