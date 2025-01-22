/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:09 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:56:10 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_vec.h"

int	square_dist2i(t_vec start, t_vec end)
{
	end.x -= start.x;
	end.y -= start.y;
	return (end.x * end.x + end.y * end.y);
}

int	dist2di(t_vecd start, t_vec end)
{
	start.x -= end.x + 0.5;
	start.y -= end.y + 0.5;
	return (sqrt(start.x * start.x + start.y * start.y));
}
