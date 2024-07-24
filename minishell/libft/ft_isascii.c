/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:20:43 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:07 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 000 && c <= 127)
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
	printf("%d", ft_isascii('f'));
	printf("%d", ft_isascii('4'));
	printf("%d", ft_isascii('/'));
	printf("%d", ft_isascii('u'));
	printf("%d", isascii('o'));
	return (0);
}*/
