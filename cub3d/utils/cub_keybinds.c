/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:54:56 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:02:34 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_keybinds.h"

void		set_keystate(t_keybinds *keybinds, int key, bool pressed)
{
	if (key == ROTATE_LEFT)
		keybinds->rotate_left = pressed;
	else if (key == ROTATE_RIGHT)
		keybinds->rotate_right = pressed;
	if (key == ROTATE_UP)
		keybinds->rotate_up = pressed;
	else if (key == ROTATE_DOWN)
		keybinds->rotate_down = pressed;
	else if (key == FORWARD_W_Z)
		keybinds->forwards = pressed;
	else if (key == BACK_S_S)
		keybinds->backwards = pressed;
	else if (key == LEFT_A_Q)
		keybinds->left = pressed;
	else if (key == RIGHT_D_D)
		keybinds->right = pressed;
	else if (key == JUMP_SPACE)
		keybinds->jump = pressed;
	else if (key == SNEAK_MAJ)
		keybinds->sneak = pressed;
}

int			key_press(int keycode, t_vars *vars)
{
	set_keystate(&(vars->player.keybinds), keycode, true);
	if (keycode == ESC)
		clean_and_exit(0, vars);
	if (keycode == MAKE_PORTAL && vars->portal.img)
		handle_portal_creation(vars);
	return (0);
}

int			key_lift(int keycode, t_vars *vars)
{
	set_keystate(&(vars->player.keybinds), keycode, false);
	return (0);
}

t_keybinds	make_keybinds(void)
{
	t_keybinds keys;

	keys.forwards = false;
	keys.backwards = false;
	keys.left = false;
	keys.right = false;
	keys.rotate_left = false;
	keys.rotate_right = false;
	keys.rotate_up = false;
	keys.rotate_down = false;
	keys.sneak = false;
	keys.jump = false;
	keys.move.x = 0;
	keys.move.y = 0;
	return (keys);
}

void		update_keybinds(t_vars *vars)
{
	t_keybinds *keys;

	keys = &(vars->player.keybinds);
	keys->move.x = 0;
	if (!(keys->forwards && keys->backwards))
	{
		if (keys->forwards)
			keys->move.x = 1;
		else if (keys->backwards)
			keys->move.x = -1;
	}
	keys->move.y = 0;
	if (!(keys->left && keys->right))
	{
		if (keys->left)
			keys->move.y = -1;
		else if (keys->right)
			keys->move.y = 1;
	}
	if (vars->player.keybinds.forwards && !vars->player.keybinds.backwards)
		normalize(&(keys->move), 0.0085);
	else
		normalize(&(keys->move), 0.0065);
}
