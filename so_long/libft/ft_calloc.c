/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:25:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:25:33 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*s;
	size_t			n;

	n = nmemb * size;
	s = malloc(n);
	if (s == 0)
		return (0);
	return (ft_memset(s, 0, n));
}
