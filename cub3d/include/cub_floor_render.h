/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor_render.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:06:54 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:06:55 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_RENDER_H
# define CUB_FLOOR_RENDER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_rot.h"

typedef struct		s_floor_render
{
	t_rot			start;
	t_rot			end;
	t_vecd			s;
	t_vecd			step;
	t_vecd			start_pos;
	t_vecd			tex;
	int				color;
	int				midpi;
	double			mid;
	double			row_len;
	double			dim;
	double			ang;
}					t_floor_render;

#endif
