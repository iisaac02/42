/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:29:37 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:44 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(const char **strs, const char *sep)
{
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	while (strs[i])
		count += ft_strlen(strs[i++]);
	return (count + ft_strlen(sep) * (i - 1));
}

char	*ft_strsjoin(const char **strs, const char *sep)
{
	char			*str;
	size_t			i;

	str = (char *)malloc(sizeof(char) * (count_str(strs, sep) + 1));
	if (str == 0)
		return (0);
	*str = 0;
	i = 0;
	while (strs[i])
	{
		if (i)
			ft_strcat(str, sep);
		ft_strcat(str, strs[i++]);
	}
	return (str);
}
