/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:32 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:00:37 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_raycast.h"

t_vec		get_collide_pos(t_trace trace)
{
	t_vec pos;

	if (trace.ray.ln_cos > trace.ray.ln_sin)
	{
		pos.x = floor(trace.ref.x + trace.ray.st_sin.x);
		pos.y = floor(trace.ref.y + trace.ray.st_sin.y + trace.rot.sin / 2);
		return (pos);
	}
	pos.x = floor(trace.ref.x + trace.ray.st_cos.x + trace.rot.cos / 2);
	pos.y = floor(trace.ref.y + trace.ray.st_cos.y);
	return (pos);
}

int			check_colide(t_vars *vars, t_vec pos)
{
	return (map_get(&vars->map, pos.x, pos.y));
}

void		render_portal(t_shape line, float offset, t_vars *vars)
{
	set_portal_strip(&(vars->img), line, &(vars->portal), offset);
}

t_img		*get_texture(t_vars *vars, t_cardinal card)
{
	if (card == EAST)
		return (&(vars->walls.north));
	if (card == WEST)
		return (&(vars->walls.south));
	if (card == NORTH)
		return (&(vars->walls.west));
	return (&(vars->walls.east));
}

t_mouseover	get_mouseover(t_vars *vars)
{
	t_trace		trace;
	t_mouseover	over;

	over.found = false;
	trace.rot = make_rot(vars->player.yaw);
	trace.ray = get_init_ray(&(trace.rot),
		vars->player.pos.x, vars->player.pos.y);
	trace.step = get_init_ray(&(trace.rot), 0, 0);
	trace.ref.x = vars->player.pos.x;
	trace.ref.y = vars->player.pos.y;
	trace.i = 0;
	while (trace.i < 15)
	{
		trace.pos = get_collide_pos(trace);
		if (check_colide(vars, trace.pos))
		{
			over.card = get_cardinal(trace);
			over.pos = trace.pos;
			over.found = true;
			break ;
		}
		cast_forward(&(trace.ray), trace.step);
		trace.i++;
	}
	return (over);
}
