/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:38 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_width(t_root *root, char *map)
{
	root->game->width = 0;
	while (map[root->game->width] && map[root->game->width] != '\n')
		root->game->width++;
	if (root->game->width == 0 || map[root->game->width] == 0)
	{
		free(map);
		root_destroy(root, "map file is invalid", 0);
	}
}
