/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:04:42 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:46 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char s[] = "come find me if you have guts";
	
	printf("%s\n", (char *)ft_memchr(s, 'v', 22));
	printf("%s\n", (char *)memchr(s, 'v', 22));
	return (0);
}*/