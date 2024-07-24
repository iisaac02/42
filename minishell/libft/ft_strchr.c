/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:02:47 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:55:23 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != uc)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

/*int	main(void)
{
	char s[] = "come find me if you have guts";
	
	printf("%s\n", ft_strchr(s, 'u'));
	printf("%s\n", strchr(s, 'u'));
	return (0);
}*/
