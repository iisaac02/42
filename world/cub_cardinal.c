/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:13 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:03:01 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_cardinal.h"

t_cardinal	get_cardinal(t_trace trace)
{
	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		if (trace.rot.sin > 0)
			return (EAST);
		else
			return (WEST);
	}
	if (trace.rot.cos > 0)
		return (NORTH);
	else
		return (SOUTH);
}

t_cardinal	get_opposite(t_cardinal card)
{
	if (card == NORTH)
		return (SOUTH);
	if (card == SOUTH)
		return (NORTH);
	if (card == (EAST))
		return (WEST);
	return (EAST);
}

t_vec		get_direction(t_cardinal card)
{
	t_vec vec;

	vec.x = 0;
	vec.y = 0;
	if (card == NORTH)
		vec.x = 1;
	else if (card == SOUTH)
		vec.x = -1;
	else if (card == EAST)
		vec.y = 1;
	else
		vec.y = -1;
	return (vec);
}
