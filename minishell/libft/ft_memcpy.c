/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:26:50 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:54:06 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest != NULL || src != NULL)
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char str1[]= "change me please";
	char str2[]= "if you insist";
	
	printf("%s\n", ft_memcpy(str1, str2, 7));
	printf("%s\n", memcpy(str1, str2, 7));
	return (0);
}*/
