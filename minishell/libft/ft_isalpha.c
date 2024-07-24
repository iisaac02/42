/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:47:57 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:52:56 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("%d", ft_isalpha('f'));
	printf("%d", ft_isalpha(4));
	printf("%d", ft_isalpha('K'));
	printf("%d", ft_isalpha(0));
	return (0);
}*/
