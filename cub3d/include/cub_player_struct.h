/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:08 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:09 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_STRUCT_H
# define CUB_PLAYER_STRUCT_H

# include "cub_keybinds_struct.h"
# include "../utils/cub_vec.h"

typedef struct		s_player
{
	t_vec3d			pos;
	t_vecd			s_pos;
	t_vec3d			render;
	t_vec3d			motion;
	t_keybinds		keybinds;
	float			health;
	double			yaw;
	double			pitch;
	double			motion_yaw;
	double			motion_pitch;
}					t_player;

#endif
