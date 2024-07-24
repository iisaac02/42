/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:56:41 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:53:24 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
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
	printf("%d", ft_isprint('f'));
	printf("%d", ft_isprint('4'));
	printf("%d", ft_isprint('/'));
	printf("%d", ft_isprint('\n'));
	printf("%d", isprint('\n'));
	return (0);

}*/
