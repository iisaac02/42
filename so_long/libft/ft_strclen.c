/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:44 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:44 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, const char *charset)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (ft_ischarset(s[i], charset))
			break ;
		i++;
	}
	return (i);
}
