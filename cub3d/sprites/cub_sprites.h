/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprites.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:50 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:56:51 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITES_H
# define CUB_SPRITES_H

# include "../cub.h"
# include "../world/cub_collide.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "cub_goomba.h"

typedef struct	s_sprite_r
{
	t_shape		draw;
	t_vec		v;
	t_vec		offset;
	int			color;
	t_vecd		pos;
	double		dist;
	double		sprite_angle;
	double		view_dist;
	float		dim;
}				t_sprite_r;

void			draw_sprites(t_vars *vars, bool skip);

#endif
