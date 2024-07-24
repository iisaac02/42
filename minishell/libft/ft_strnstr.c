/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:06:38 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:26 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	if (needle[n] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < size)
	{
		while (haystack[i + n] != '\0' && haystack[i + n] == needle[n])
		{
			n++;
		}
		if (needle[n] == '\0' && i + n <= size)
		{
			return ((char *)haystack + (i));
		}
		n = 0;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str[] = "you cannot hide from me needle";
	char needle[] = "hide";

	printf("%s \n", ft_strnstr(str, needle, 14));
	printf("%s \n", strnstr(str, needle, 14));
	return (0);
}*/
