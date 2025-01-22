/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_star_cardinal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:53 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_star_cardinal.h"

t_vec	get_neighbor(int rot, t_vec origin)
{
	if (rot == 0)
		origin.x++;
	else if (rot == 1)
		origin.x--;
	else if (rot == 2)
		origin.y++;
	else if (rot == 3)
		origin.y--;
	return (origin);
}

bool	is_in_map(t_map *map, t_vec pos)
{
	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= map->size.x || pos.y >= map->size.y)
		return (false);
	return (true);
}
