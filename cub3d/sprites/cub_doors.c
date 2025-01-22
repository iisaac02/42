/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_doors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:15 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:01:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_doors.h"

void	setup_door(t_door_r *dr, t_vars *vars, t_sprite *s)
{
	dr->rotated = s->dead;
	dr->inverted = false;
	dr->pos.x = s->pos.x - vars->player.render.x;
	dr->pos.y = s->pos.y - vars->player.render.y;
	if (dr->rotated)
	{
		dr->pos.x += 0.5;
		dr->pos.y -= ease_in_out(s->last_hurt / 25.0);
		dr->end.x = dr->pos.x;
		dr->end.y = dr->pos.y + 1;
	}
	else
	{
		dr->pos.y += 0.5;
		dr->pos.x -= ease_in_out(s->last_hurt / 25.0);
		dr->end.x = dr->pos.x + 1;
		dr->end.y = dr->pos.y;
	}
	dr->dist = distance(dr->pos);
	dr->end_dist = distance(dr->end);
	dr->sprite_angle = atan2(dr->pos.y, dr->pos.x) - vars->player.yaw;
	dr->end_angle = atan2(dr->end.y, dr->end.x) - vars->player.yaw;
	dr->view_dist = vars->resx * vars->fov;
}

void	setup_door_draw(t_door_r *dr, t_vars *vars)
{
	dr->draw.x = vars->resx / 2 + (tan(dr->sprite_angle)) * dr->view_dist;
	dr->draw.width = (vars->resx / 2 + (tan(dr->end_angle)) * dr->view_dist)
		- dr->draw.x;
	if (dr->draw.width < 0)
	{
		dr->draw.x += dr->draw.width;
		dr->draw.width *= -1;
		swap_d(&dr->sprite_angle, &dr->end_angle);
		swap_d(&dr->dist, &dr->end_dist);
		dr->inverted = true;
	}
}

void	draw_door_line(t_door_r *dr, t_vars *vars, t_vec v, double linedist)
{
	dr->draw.height = (dr->view_dist / (cos(dr->sprite_angle) * dr->dist) *
		(1 - dr->ratio2)) + (dr->view_dist / (cos(dr->end_angle)
		* dr->end_dist) * (dr->ratio2));
	if (dr->draw.height <= 0)
		return ;
	dr->draw.y = (vars->resy - dr->draw.height + vars->player.pitch * 4) / 2;
	dr->draw.y += dr->draw.height * vars->player.render.z;
	dr->offset.x = fmin(dr->ratio * dr->sprite->texture->width,
		dr->sprite->texture->width - 1);
	while (++v.y < dr->draw.height && dr->draw.y + v.y < dr->img->height)
	{
		if (dr->draw.y + v.y < 0)
			v.y = -dr->draw.y;
		if (linedist >= vars->depth[dr->draw.x + v.x])
			continue;
		dr->offset.y = fmin(v.y / (double)dr->draw.height
			* dr->sprite->texture->height, dr->sprite->texture->height - 1);
		dr->dim = 1 - fmin(1, (dr->dist - 1) / 9);
		if (!vars->should_dim)
			dr->dim = 1;
		dr->color = get_pixel(dr->sprite->texture, dr->offset.x, dr->offset.y);
		if (dr->color != 0)
			set_pixel(dr->img, dr->draw.x + v.x, dr->draw.y + v.y,
					color_dim(dr->color, dr->dim));
	}
}

void	draw_door_sprite(t_door_r *dr, t_vars *vars)
{
	t_vec	v;

	v.x = -1;
	v.y = -1;
	while (++v.x < dr->draw.width && dr->draw.x + v.x < dr->img->width)
	{
		if (dr->draw.x + v.x < 0)
			v.x = -dr->draw.x;
		dr->curr_angle = atan2(((dr->draw.x + v.x) / (double)vars->resx) - 0.5,
			vars->fov);
		dr->ratio2 = v.x / (double)dr->draw.width;
		dr->ratio = get_angdist(dr->sprite_angle, dr->curr_angle) /
			get_angdist(dr->sprite_angle, dr->end_angle);
		if (dr->inverted)
			dr->ratio = 1 - dr->ratio;
		if (ease_in_out(dr->sprite->last_hurt / 25.0) > dr->ratio * 2)
			continue;
		dr->end = dr->pos;
		if (dr->rotated)
			dr->end.y += dr->ratio;
		else
			dr->end.x += dr->ratio;
		draw_door_line(dr, vars, v, distance(dr->end));
	}
}

bool	draw_door(t_img *img, t_vars *vars, t_sprite s)
{
	t_door_r dr;

	setup_door(&dr, vars, &s);
	if (dr.dist > vars->render_distance)
		return (false);
	if (fabs(get_angdist(dr.sprite_angle, 0)) > M_PI / 2 ||
		fabs(get_angdist(dr.end_angle, 0)) > M_PI / 2)
		return (true);
	setup_door_draw(&dr, vars);
	dr.sprite = &s;
	dr.img = img;
	draw_door_sprite(&dr, vars);
	return (1);
}
