/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:25:22 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:54:19 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d <= s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

/*int	main(void)
{
	char str1[]= "change me please";
	char str2[]= "if you insist";
	
	printf("%s\n", ft_memmove(str1, str2, 7));
	printf("%s\n", memmove(str1, str2, 7));
	return (0);
}*/
