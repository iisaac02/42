/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:23:41 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/06 14:39:36 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Modifica otro string creado, según se indique en la subfunción f.

#include "libft.h"
//#include <stdio.h>

/*char	f(unsigned int pos, char let)
{
	if (pos % 2)
		let = 'x';
	return (let);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
/*
int	main(void)
{
	printf ("%s\n", ft_strmapi("hola", *f));
	return (0);
}*/