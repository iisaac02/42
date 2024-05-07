/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:12:51 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/02 19:33:43 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Concatena dos strings
//Añadir todas las funciones al compilar

#include "libft.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		cont;

	if (!s1 || !s2)
		return (NULL);
	cont = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (cont + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*str;

	s1 = "Hola ";
	s2 = "Mundo";
	str = ft_strjoin(s1, s2);
	printf("%s\n", str);
	return (0);
}*/