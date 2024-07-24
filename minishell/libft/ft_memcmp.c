/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:11 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:59 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while (str1[i] == str2[i] && i < n -1)
	{
		i++;
	}
	if (str1[i] == str2[i])
	{
		return (0);
	}
	else
	{
		return (str1[i] - str2[i]);
	}
}

/*int	main(void)
{
	char s1[] = "Hello world";
	char s2[] = "Hello world hola";
	size_t i = 15;

	printf("%d \n", ft_memcmp(s1, s2, i));
	printf("%d \n", memcmp(s1, s2, i));
	return (0);
}*/
