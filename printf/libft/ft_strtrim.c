/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:37:51 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/02 21:04:18 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Elimina los caracteres indicados en set del principio y del final de s1
//Añadir todas las funciones al compilar

#include "libft.h"
//#include <stdio.h>

int	ft_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	end = (int)ft_strlen(s1);
	while (s1[start] && ft_check(s1[start], set))
		start++;
	while (end > start && ft_check(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*s1;
	char	*set;
	char	*str;

	s1 = "Hola Mundo!";
	set = "Hol";
	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	return (0);
}*/