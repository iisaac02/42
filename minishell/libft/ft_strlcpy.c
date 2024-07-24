/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:35:49 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:55:56 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] != '\0' && i < n - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char str1[]= "change me please";
	char str2[]= "if you insist";
	
	printf("%lu\n", ft_strlcpy(str1, str2, 10));
	printf("%lu\n", strlcpy(str1, str2, 10));
	printf("%s\n", str1);
	return (0);
}*/
