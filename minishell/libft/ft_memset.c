/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 09:39:36 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:54:32 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned int	count;
	unsigned char	*d;

	count = 0;
	d = (unsigned char *)dest;
	while (count < n)
	{
		d[count] = c;
		count++;
	}
	return (dest);
}

/*int	main(void)
{
	char str[]= "change me please";
	
	printf("%s\n", ft_memset(str, 'u', 5));
	printf("%s\n", memset(str, 'u', 5));
	return (0);
}*/
