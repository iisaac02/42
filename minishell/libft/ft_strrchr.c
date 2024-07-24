/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:10:31 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:34 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (s[i] != (char) c)
	{
		if (i == 0)
		{
			return (NULL);
		}
		i--;
	}
	return ((char *) &s[i]);
}

/*int	main(void)
{
	char s[] = "come find me if you have guts";
	
	printf("%s\n", ft_strrchr(s, 'u'));
	printf("%s\n", strrchr(s, 'u'));
	return (0);
}*/
