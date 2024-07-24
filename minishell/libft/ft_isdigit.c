/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:39 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:15 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("%d", ft_isdigit('f'));
	printf("%d", ft_isdigit('4'));
	printf("%d", ft_isdigit('K'));
	printf("%d", ft_isdigit('0'));
	printf("%d", ft_isdigit('\0'));
	return (0);
}*/
