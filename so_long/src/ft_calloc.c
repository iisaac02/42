/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:46:31 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/14 11:09:50 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;

	bzero = malloc(count * size);
	if (!bzero)
		return (0);
	ft_bzero(bzero, count * size);
	return (bzero);
}
