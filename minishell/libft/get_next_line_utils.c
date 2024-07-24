/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:21:18 by aiturria          #+#    #+#             */
/*   Updated: 2024/02/11 13:52:34 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	ft_gnlstrlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (free (str), 0);
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_gnlstrchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (free (s), NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char			*joined;
	unsigned int	i;
	unsigned int	n;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (free (s2), NULL);
		s1[0] = '\0';
	}
	i = ft_gnlstrlen(s1);
	n = ft_gnlstrlen(s2);
	joined = (char *)malloc((i + n + 1) * sizeof(char));
	if (!joined)
		return (free(s1), NULL);
	i = -1;
	n = 0;
	while (s1[++i] != '\0')
		joined[i] = s1[i];
	while (s2[n] != '\0')
		joined[i++] = s2[n++];
	joined[i] = '\0';
	free (s1);
	return (joined);
}
