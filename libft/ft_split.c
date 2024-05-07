/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:10:42 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/07 16:40:01 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Separa una cadena en palabras usando el carácter c como separador
//clerIncluir todas las funciones al compilar

#include "libft.h"
//#include <stdio.h>

int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			j++;
		i++;
	}
	return (j);
}

int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_str(int *i, char const *s, int j)
{
	char	*k;
	int		l;

	l = 0;
	k = malloc(sizeof(char) * (j + 1));
	if (!k)
		return (NULL);
	while (l < j)
	{
		k[l] = s[*i];
		l++;
		(*i)++;
	}
	k[l] = 0;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		f;
	int		i;
	int		l;
	char	**newfunc;
	char	*k;

	i = -1;
	f = ft_count(s, c);
	newfunc = malloc(sizeof(char *) * (f + 1));
	if (!newfunc)
		return (NULL);
	l = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			k = ft_str(&i, s, ft_wordlen(s + i, c));
			if (!k)
				return (NULL);
			newfunc[l++] = k;
			i--;
		}
	}
	newfunc[l] = NULL;
	return (newfunc);
}
/*
int	main(void)
{
	char const	*s = "hola como estas";
	char		c = ' ';
	char		**result = ft_split(s, c);

	printf("%s\n", s);
	if (result)
	{
		int i = 0;
		while (result[i])
		{
			printf("%s\n", result[i]);
			i++;
		}
		free(result);
	}
	return (0);
}*/