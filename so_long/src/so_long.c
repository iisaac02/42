/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:56:49 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/15 11:21:40 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

void	check_map_extension(char *map, t_list *d)
{
	int	i;

	i = ft_strlen(map);
	if (i > 2 && map[i - 4] == '.' && map[i - 3] == 'b'
		&& map[i - 2] == 'e' && map[i - 1] == 'r')
		;
	else
		ft_error(d, 6);
}

void	init_img(t_list *d)
{
	int	w;
	int	h;

	w = 50;
	h = 50;
	d->y = (ft_strlen(d->big_line) / d->width_l + 1) * 50;
	d->x = (d->width_l - 1) * 50;
	d->bush = mlx_xpm_file_to_image(d->mlx, "img/bush.xpm", &w, &h);
	d->fond = mlx_xpm_file_to_image(d->mlx, "img/fond.xpm", &w, &h);
	d->poke = mlx_xpm_file_to_image(d->mlx, "img/poke.xpm", &w, &h);
	d->npcstart = mlx_xpm_file_to_image(d->mlx, "img/npc.xpm", &w, &h);
	d->npc = mlx_xpm_file_to_image(d->mlx, "img/npc.xpm", &w, &h);
	d->npcmv = mlx_xpm_file_to_image(d->mlx, "img/npcmv.xpm", &w, &h);
	d->npcleft = mlx_xpm_file_to_image(d->mlx, "img/npcleft.xpm", &w, &h);
	d->npclmv = mlx_xpm_file_to_image(d->mlx, "img/npcleftmv.xpm", &w, &h);
	d->npcright = mlx_xpm_file_to_image(d->mlx, "img/npcright.xpm", &w, &h);
	d->npcrmv = mlx_xpm_file_to_image(d->mlx, "img/npcrightmv.xpm", &w, &h);
	d->npcback = mlx_xpm_file_to_image(d->mlx, "img/npcback.xpm", &w, &h);
	d->npcbmv = mlx_xpm_file_to_image(d->mlx, "img/npcbackmv.xpm", &w, &h);
	d->imgexit = mlx_xpm_file_to_image(d->mlx, "img/imgexit.xpm", &w, &h);
}

int	main(int argc, char **argv)
{
	t_list	*d;

	if (argc != 2)
	{
		write (1, "Incorrect arguments number\n", 27);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_list));
	if (!d)
		return (0);
	d->mlx = mlx_init;
	init_data(d, argv[1]);
	mlx_key_hook(d->win, key_press, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}

int	init_data(t_list *d, char *map)
{
	d->moves = 0;
	check_map_extension(map, d);
	read_map(map, d);
	init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	print_map(d);
	return (0);
}
