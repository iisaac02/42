/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:17:56 by aiturria          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:25 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	n;

	i = ft_strlen(s1);
	n = ft_strlen(s2);
	joined = malloc(i + n + 1);
	if (!joined)
		return (NULL);
	i = 0;
	n = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		joined[i] = s2[n];
		i++;
		n++;
	}
	joined[i] = '\0';
	return (joined);
}

/*int	main(void)
{
	char s1[] = "we will be the one";
	char s2[] = "we have always been";

	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/
