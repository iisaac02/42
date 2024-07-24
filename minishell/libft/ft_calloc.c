/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:23:37 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:43:55 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*ptr;
	unsigned int		total;
	unsigned int		i;

	total = count * size;
	i = 0;
	if (count == 0 || size == 0)
		return (ptr = (void *)malloc(0));
	ptr = (void *) malloc(total);
	if (ptr == NULL)
		return (NULL);
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

/*int	main(void)
{
	printf("%p\n", ft_calloc(10, 5));
	printf("%p\n", calloc(10, 5));
}*/
