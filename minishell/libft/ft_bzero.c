/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:00:42 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:43:45 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	unsigned int	count;
	unsigned char	*s;

	count = 0;
	s = str;
	while (count < n)
	{
		s[count] = '\0';
		count++;
	}
}

/*int	main(void)
{
	char str1[] = "zero me please";
	char str2[] = "zero me please";
	int i = 0;

	ft_bzero(str1, 5);
	bzero(str2, 5);
	
	while (i < 15)
	{
		printf("%c", str1[i]);
		printf("%c", str2[i]);
		i++;
	}
	return (0);
}*/
