/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:06:09 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:44:07 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int	main(void)
{
	printf("%d", ft_isalnum('f'));
	printf("%d", ft_isalnum('4'));
	printf("%d", ft_isalnum('/'));
	printf("%d", ft_isalnum('+'));
	return (0);
}*/
