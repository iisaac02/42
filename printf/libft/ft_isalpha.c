/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:34:40 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/11/30 17:09:50 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Comprueba si es alfabético

#include "libft.h"
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/*
int main(void)
{
	char	ch;
	printf("Introduce un carácter: ");
	scanf("%c", &ch);
	
	if (ft_isalpha(ch)) {
		printf("%c es un cáracter alfabético.\n", ch);
	} else {
		printf("%c no es un carácter alfabético.\n", ch);
	}
	
	return (0);
}*/