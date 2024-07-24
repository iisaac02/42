/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:03:58 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/12 16:46:12 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*static char	*ft_substring(char const *s, int j, char **result, int k)
{
	result[k] = ft_substr(s, 0, j);
	if (!result[k])
	{
		while (k > 0)
			free(result[--k]);
		free(result);
		return (NULL);
	}
	return (result[k]);
}*/

static int	ft_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

/*char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		k;
	int		j;

	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	words = 0;
	k = 0;
	while (s[k] && words < ft_words(s, c))
	{
		while (s[k] && s[k] == c)
			k++;
		j = k;
		while (s[k] && s[k] != c)
			k++;
		if (j != k)
			result[words++] = ft_substr(s, j, (k - j));
	}
	result[words] = NULL;
	return (result);
}*/

static char	**ft_freeall(char **result, int k)

{
	while (k > 0)
	{
		free(result[--k]);
	}
	free(result);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		k;
	int		j;

	words = ft_words(s, c);
	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	k = 0;
	while ((s) && k < words)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		result[k] = ft_substr(s, 0, j);
		if (!result[k])
			return (ft_freeall(result, k));
		k++;
		s += j;
	}
	result[k] = NULL;
	return (result);
}

/*char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			result[k] = ft_substr(s, i, j);
			if (!result[k])
			{
				while (k > 0)
					free(result[--k]);
				free(result);
				return (NULL);
			}
			k++;
			i += j;
		}
	}
	result[k] = NULL;
	return (result);
}*/

/*int	main(void)
{
	char	*s = " holaquetal";
	char	**split = ft_split(s, ' ');
	int		i = 0;

    while (split[i] != NULL)
    {
        printf("%s\n", split[i]);
        i++;
    }
	return (0);
}*/

/*#include <stdlib.h> //other form of the same words

static int	ft_words(const char *s, char c)
{
	int words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}*/