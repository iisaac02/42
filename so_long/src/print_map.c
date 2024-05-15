/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:29:24 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/15 11:18:46 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	calc_xy(char r, int i, t_list *d)
{
	int	x;
	int	y;

	y = (i / d->width_l) * 50;
	x = (i % d->width_l) * 50;
	if (d->errors == 0)
	{
		if (r == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->poke, x, y);
		if (r == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->imgexit, x, y);
		if (r == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->bush, x, y);
		if (r == '0')
			mlx_put_image_to_window(d->mlx, d->win, d->fond, x, y);
		if (r == 'P')
			mlx_put_image_to_window(d->mlx, d->win, d->npcstart, x, y);
	}
}

void	print_map(t_list *d)
{
	int	i;

	i = 0;
	while (d->big_line[i])
	{
		if (d->big_line[i] == '\n')
			i++;
		if (d->big_line[i] != 'C' && d->big_line[i] != 'E'
			&& d->big_line[i] != '1'
			&& d->big_line[i] != '0' && d->big_line[i] != 'P')
			exit (0);
		if (d->big_line[i] == 'C')
			calc_xy('C', i, d);
		if (d->big_line[i] == 'E')
			calc_xy('E', i, d);
		if (d->big_line[i] == '1')
			calc_xy('1', i, d);
		if (d->big_line[i] == '0')
			calc_xy('0', i, d);
		if (d->big_line[i] == 'P')
			calc_xy('P', i, d);
		i++;
	}
}
