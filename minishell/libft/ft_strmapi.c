/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:50:33 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:56:11 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	while (i--)
	{
		result[i] = f(i, s[i]);
	}
	return (result);
}
