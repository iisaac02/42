/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:19:01 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/13 11:05:20 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(map + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		die("invalid number of arguments", 0);
	if (check_extension(argv[1]) == 0)
		die("The argument must be .ber", 0);
	root = root_init(argv[1]);
	draw(root);
	mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
	mlx_hook(root->mlx_win, 3, 1L << 1, key_release, root);
	mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
	mlx_loop(root->mlx);
	return (0);
}
