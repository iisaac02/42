/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_isvalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:23 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:23 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	isborder(t_root *root, int i)
{
	if (i < root->game->width
		|| i > (root->game->width + 1) * (root->game->height - 1)
		|| i % (root->game->width + 1) == 0
		|| i % (root->game->width + 1) == root->game->width - 1)
		return (1);
	return (0);
}

static void	isvalid(t_root *root, char *map, int i)
{
	if (map[i] == 'P')
		root->game->count_player++;
	else if (map[i] == 'E')
		root->game->count_exit++;
	else if (map[i] == 'C')
		root->game->count_coll++;
	else if (map[i] == '1' || map[i] == '0')
		return ;
	else
	{
		free(map);
		root_destroy(root, "map content is invalid", 0);
	}
}

void	map_isvalid2(t_root *root, char	*map)
{
	if (root->game->count_exit != 1)
	{
		free(map);
		root_destroy(root, "The map must have one exit", 0);
	}
	if (root->game->count_coll < 1)
	{
		free(map);
		root_destroy(root, "The map must have at least one collectable", 0);
	}
}

void	map_isvalid(t_root *root, char *map)
{
	int	i;

	i = -1;
	while (map[++i] != 0)
	{
		if (map[i] == '\n')
			continue ;
		if (isborder(root, i))
		{
			if (map[i] != '1')
			{
				free(map);
				root_destroy(root, "map isn't surrounded by walls", 0);
			}
		}
		else
			isvalid(root, map, i);
	}
	if (root->game->count_player != 1)
	{
		free(map);
		root_destroy(root, "The map must have one player", 0);
	}
	map_isvalid2(root, map);
}
