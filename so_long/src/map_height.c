/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:11 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:11 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(t_root *root, char *map)
{
	int	i;
	int	j;

	root->game->height = 1;
	i = root->game->width + 1;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i + j] != 0 && map[i + j] != '\n')
			j++;
		if (root->game->width != j)
		{
			free(map);
			root_destroy(root, "map format is invalid", 0);
		}
		i += root->game->width + 1;
		root->game->height++;
	}
}
