/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:34 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:34 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(t_root *root, char *map)
{
	map_width(root, map);
	map_height(root, map);
	map_isvalid(root, map);
	root->game->coll = malloc(sizeof(t_coord) * root->game->count_coll);
	if (root->game->coll == 0)
	{
		free(map);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
	if (root->game->map == 0)
	{
		free(map);
		root_destroy(root, "map_parsing(): malloc()", errno);
	}
	map_parsing(root, map);
}
