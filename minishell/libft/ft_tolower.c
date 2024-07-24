/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:52:35 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:58 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	return (c);
}

/*int	main(void)
{
	printf("%d", ft_tolower('D'));
	printf("%d", tolower('D'));
	printf("%c", ft_tolower('D'));
	printf("%c", tolower('D'));
	return (0);
}*/