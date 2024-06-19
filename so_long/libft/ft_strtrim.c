/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:29:41 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:41 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	int			start;
	int			end;
	int			i;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (s1[start] && ft_ischarset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_ischarset(s1[end - 1], set))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == 0)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
