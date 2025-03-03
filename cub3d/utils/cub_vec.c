/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:00 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:26 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_vec.h"

void	normalize(t_vecd *vec, double scale)
{
	double len;

	len = sqrt(vec->x * vec->x + vec->y * vec->y);
	if (len < 0.0001)
	{
		vec->x = 0;
		vec->y = 0;
		return ;
	}
	vec->x /= len;
	vec->y /= len;
	vec->x *= scale;
	vec->y *= scale;
}

double	calc_sqrtlen(t_vecd v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	distancemid2(t_vecd start, t_vecd end)
{
	end.x -= start.x + 0.5;
	end.y -= start.y + 0.5;
	return (sqrt(end.x * end.x + end.y * end.y));
}

double	square_dist(t_vec3d start, t_vecd end)
{
	end.x -= start.x;
	end.y -= start.y;
	return (end.x * end.x + end.y * end.y);
}

double	square_dist_mid(t_vec3d start, t_vecd end)
{
	end.x -= start.x - 0.5;
	end.y -= start.y - 0.5;
	return (end.x * end.x + end.y * end.y);
}
