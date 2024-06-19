/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:18:30 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:18:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_matrix(t_root *root, char *map, int **m, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(m[i++]);
	free(m);
	root->game->map = 0;
	free(map);
	root_destroy(root, "map_parsing(): malloc()", errno);
}

static void	get_coord(t_root *root, char *map, int k, int *obj)
{
	if (map[k] == 'P')
	{
		root->game->player.x = k % (root->game->width + 1);
		root->game->player.y = k / (root->game->width + 1);
		map[k] = '0';
	}
	else if (map[k] == 'E')
	{
		root->game->exit.x = k % (root->game->width + 1);
		root->game->exit.y = k / (root->game->width + 1);
		map[k] = '0';
	}
	else if (map[k] == 'C')
	{
		root->game->coll[*obj].x = k % (root->game->width + 1);
		root->game->coll[*obj].y = k / (root->game->width + 1);
		map[k] = '0';
		(*obj)++;
	}
}

void	map_parsing(t_root *root, char *map)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < root->game->height)
	{
		root->game->map[j] = malloc(sizeof(int) * root->game->width);
		if (root->game->map[j] == 0)
			free_matrix(root, map, root->game->map, j);
		i = 0;
		while (i < root->game->width)
		{
			get_coord(root, map, k, &obj);
			root->game->map[j][i++] = map[k++] - 48;
		}
		k++;
	}
}
