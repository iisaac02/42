/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:49:15 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:49:16 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_map.h"

t_map	make_empty(t_vec size)
{
	t_map	map;
	int		i;

	map.buf_size = size.x * size.y;
	map.data = malloc(sizeof(char) * map.buf_size);
	if (!map.data)
	{
		map.buf_size = 0;
		return (map);
	}
	i = 0;
	while (i < map.buf_size)
		map.data[i++] = MAP_EMPTY;
	map.size = size;
	return (map);
}

void	map_set(t_map *map, int x, int y, int value)
{
	int pos;

	pos = y * map->size.x + x;
	if (x < 0 || y < 0 || x >= map->size.x || y >= map->size.y)
		return ;
	map->data[pos] = value;
}

int		map_get(t_map *map, int x, int y)
{
	int pos;

	pos = y * map->size.x + x;
	if (x < 0 || y < 0 || x >= map->size.x || y >= map->size.y)
		return (0);
	return (map->data[pos] == MAP_BLOCK);
}

int		map_get_val(t_map *map, int x, int y)
{
	int pos;

	pos = y * map->size.x + x;
	if (x < 0 || y < 0 || x >= map->size.x || y >= map->size.y)
		return (MAP_EMPTY);
	return (map->data[pos]);
}

void	clear_map(t_map *map)
{
	if (map->data)
	{
		free(map->data);
		map->data = NULL;
	}
}
