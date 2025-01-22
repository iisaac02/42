/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:37 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 20:37:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_hud.h"

void	draw_hud(t_vars *vars)
{
	t_shape shape;

	if (!vars->dash.img || vars->resx < 420 || vars->resy < 230)
		return ;
	shape.width = 210;
	shape.height = 15;
	shape.x = 20;
	shape.y = vars->resy - 35;
	rect(&(vars->img), shape, 0);
	shape.width = 210 * vars->player.health;
	rect(&(vars->img), shape, 0x00CD3D24);
	shape.height = 5;
	shape.y += 10;
	rect(&(vars->img), shape, 0x00B22D17);
	make_blur_opt(vars->blur, false);
	draw_minimap(vars);
	put_alpha_window(vars, &vars->dash, 0,
		vars->resy - vars->dash.height - (LINUX ? 1 : 0));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->blur.dest.img,
		vars->blur.shape.x, vars->blur.shape.y);
}

void	draw_death(t_vars *vars)
{
	if (vars->player.health == -1000)
		return ;
	fill_img(vars->img, 0x50BE3F3B, 0, vars->img.height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_string_put(vars->mlx, vars->win, vars->img.width / 2 - 45,
		vars->img.height / 2 - 10, 0x00FFFFFF, "GAME OVER");
	vars->player.health = -1000;
}

void	draw_cursor(t_vars *vars)
{
	t_shape shape;
	int		color;

	if (!vars->gun.img)
		return ;
	color = color_dim(0xFFFFFF, 1 - fmin(vars->shoot, 40) / 40.0) | 0xBB << 24;
	shape.width = 1;
	shape.height = 4;
	shape.x = (vars->resx - 30) / 2 + 1;
	shape.y = (vars->resy - 30) / 2 - 2;
	rect(&(vars->img), shape, color);
	shape.x += 28;
	rect(&(vars->img), shape, color);
	shape.x -= 16;
	shape.width = 4;
	shape.height = 1;
	shape.y -= 13;
	rect(&(vars->img), shape, color);
	shape.y += 28;
	rect(&(vars->img), shape, color);
	shape.y -= 14;
	shape.x += 1;
	shape.width = 2;
	shape.height = 2;
	rect(&(vars->img), shape, color);
}

void	render_hand(t_vars *vars)
{
	t_vec	pos;

	if (!vars->gun.img || vars->resx < 420)
		return ;
	pos.y = 3 + cos(vars->time / 4.0 + 34) * 3 * vars->bob
			+ vars->player.pos.z * 14;
	pos.x = 3 + sin(vars->time / 4.8 + 56) * 3 * vars->bob
			- vars->player.motion_yaw * 200;
	put_alpha_window(vars, &vars->gun, vars->resx
	- vars->gun.width + pos.x, vars->resy - vars->gun.height + pos.y);
}

void	draw_skybox(t_vars *vars)
{
	t_vec	pos;

	if (vars->skybox.img && !LINUX)
		fill_img(vars->img, 0xFF000000, 0, fmax(0, vars->img.height / 2 +
			vars->player.pitch * 2 + 1));
	else if (!vars->skybox.img)
	{
		fill_img(vars->img, vars->top_color, 0, fmax(0, vars->img.height / 2 +
			vars->player.pitch * 2 + 1));
		return ;
	}
	pos.y = vars->player.pitch * 2 - vars->resy / 2 + 2;
	pos.x = fmod(-vars->player.yaw / 2 * vars->resx, vars->resx * 3.14);
	put_alpha_window(vars, &(vars->skybox), pos.x, pos.y);
	if (pos.x > 0)
		put_alpha_window(vars, &(vars->skybox),
		pos.x - vars->skybox.width + 4, pos.y);
	if (pos.x < 0 && pos.x + vars->skybox.width > 0)
		put_alpha_window(vars, &(vars->skybox),
		pos.x + vars->skybox.width - 4, pos.y);
}
