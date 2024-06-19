/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:29:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:33 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			n;

	n = ft_strlen(s) + 1;
	while (n--)
		if (s[n] == (unsigned char)c)
			return ((char *)s + n);
	return (0);
}
