/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:35:09 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:55:50 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	d;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	d = 0;
	while (dest[d] != '\0')
		d++;
	d_len = d;
	s_len = 0;
	while (src[s_len] != '\0')
		s_len++;
	if (size == 0 || size <= d_len)
		return (s_len + size);
	while (src[i] != '\0' && i < size - d_len -1)
	{
		dest[d] = src[i];
		i++;
		d++;
	}
	dest[d] = '\0';
	return (d_len + s_len);
}

/*int	main(void)
{
	char str1[31] = "bbbbbcccccddddd";
	char str2[31] = "aaaaa";
	char str3[31] = "aaaaa";
	unsigned int size = 30;

	printf("%lu \n", ft_strlcat(str2, str1, size));
	printf("%lu \n", strlcat(str3, str1, size));
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	return (0);
}*/
