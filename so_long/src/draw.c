/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:17:48 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:17:48 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_square(t_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 64)
	{
		i = 0;
		while (i < 64)
		{
			color = get_pixel(img, i, j);
			if (color != rgb_to_int(0, 255, 255, 255))
				draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_env(t_root *root, int i, int j)
{
	int	k;

	if (root->game->exit.x == i && root->game->exit.y == j)
		draw_square(root, root->exit, i * 64, j * 64);
	k = -1;
	while (++k < root->game->count_coll)
		if (root->game->coll[k].x == i && root->game->coll[k].y == j)
			draw_square(root, root->coll, i * 64, j * 64);
	if (root->game->player.x == i && root->game->player.y == j)
		draw_square(root, root->player, i * 64, j * 64);
}

static void	draw_map(t_root *root)
{
	int	i;
	int	j;

	j = 0;
	while (j < root->game->height)
	{
		i = 0;
		while (i < root->game->width)
		{
			if (root->game->map[j][i] == 1)
				draw_square(root, root->wall, i * 64, j * 64);
			else
				draw_square(root, root->ground, i * 64, j * 64);
			draw_env(root, i, j);
			i++;
		}
		j++;
	}
}

void	draw(t_root *root)
{
	draw_map(root);
	mlx_put_image_to_window(root->mlx, root->mlx_win, root->mlx_img, 0, 0);
}
