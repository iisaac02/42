/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:39:38 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:57:06 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	return (c);
}

/*int	main(void)
{
	printf("%d", ft_toupper('+'));
	printf("%d", toupper('+'));
	printf("%c", ft_toupper('+'));
	printf("%c", toupper('+'));
	return (0);
}*/
