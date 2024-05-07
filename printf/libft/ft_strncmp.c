/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:46 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:13:28 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compara dos strings

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0 || s1 == s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && (size_t)i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	s1[] = "Hola";
	char 	s2[] = "HOLA";
	int		n = 3;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
	return (0);
}*/