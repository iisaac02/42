/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_pathfinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:36 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:37 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_pathfinder.h"

void	refresh_pathfinding(t_vars *vars)
{
	t_vec	startp;

	if (vars->time % 60 != 0)
		return ;
	if (vars->pathfinder.x == -1)
		return ;
	startp.x = floor(vars->player.pos.x);
	startp.y = floor(vars->player.pos.y);
	if (vars->last_path)
		free(vars->last_path);
	vars->last_path = astar(&vars->map, startp, vars->pathfinder, 2000);
}
