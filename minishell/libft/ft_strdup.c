/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:25:47 by aiturria          #+#    #+#             */
/*   Updated: 2024/06/27 09:07:55 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		count++;
	}
	ptr = malloc(count + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int	main(void)
{
	char s1[] = "switch to your new home";

	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	return (0);
}*/
