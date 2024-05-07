/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:57:30 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/06 14:33:32 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Modifica el mismo string según se indique en la subfunción f.

#include "libft.h"
//#include <stdio.h>

/*void	f(unsigned int pos, char *let)
{
	if (pos == 2)
		*let = 'w';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f (i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Hola";

	ft_striteri (str, *f);
	printf("%s\n", str);
	return (0);
}*/