/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 08:20:57 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:51 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	n;
	unsigned int	k;

	k = ft_strlen(s);
	n = 0;
	if (start > k)
		len = 0;
	else if (start + len > k)
		len = k - start;
	s1 = malloc(len + 1);
	if (!s1)
		return (NULL);
	while (n < len)
	{
		s1[n] = s[start + n];
		n++;
	}
	s1[n] = '\0';
	return (s1);
}

	/*char			*s1;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	s1 = malloc(len + 1);
	if (s1 == NULL)
		return (NULL);
	while (i < start)
	{
		if (s[i] == '\0')
		{
			free(s1);
			return (NULL);
		}
		i++;
	}
	while (s[i + n] != '\0' && n < len)
	{
		s1[n] = s[i + n];
		n++;
	}
	s1[n] = '\0';
	return (s1);
}

int	main(void)
{
	char s[] = "gimme a part of this";

	printf("%s\n", ft_substr(s, 20, 5));
	return (0);
}*/
