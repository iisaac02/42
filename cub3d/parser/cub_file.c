/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:11 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_file.h"

int	load_map(t_vars *vars, t_line *file)
{
	t_vec p;

	p.y = 0;
	while (file)
	{
		p.x = 0;
		while (p.x < file->size)
		{
			if (!set_map(vars, file->line[p.x], p))
				handle_error(vars, "Cub is unproperly formated.", file->line);
			p.x++;
		}
		p.y++;
		file = file->next;
	}
	if (!is_map_valid(&(vars->map)))
		handle_error(vars, "Map is not enclosed.", NULL);
	handle_door_rotation(vars);
	return (0);
}

int	load_f(char *filepath, t_vars *vars)
{
	t_line	*file;
	t_vec	size;

	file = NULL;
	load_file(filepath, &(file), 0);
	vars->file = file;
	if (!vars->file)
		handle_error(vars, "Could not load file.", filepath);
	while (file)
	{
		if (!file->line[0] || read_argument(vars, file))
			file = file->next;
		else
			break ;
	}
	size = get_map_size(file);
	if (size.x == 0)
		handle_error(vars, "Map grid is empty.", NULL);
	vars->map = make_empty(size);
	if (!vars->map.data)
		handle_error(vars, "Failed to initialize map.", NULL);
	return (load_map(vars, file));
}
