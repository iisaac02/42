/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:28:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:28:59 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*d;

	d = (char *)malloc(ft_strlen(s) + 1);
	if (d == 0)
		return (0);
	ft_strcpy(d, s);
	return (d);
}
