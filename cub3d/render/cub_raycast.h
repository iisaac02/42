/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:27 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:58:28 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_RAYCAST_H
# define CUB_RAYCAST_H

# include "../cub.h"
# include "../world/cub_cardinal.h"
# include "../world/cub_portal.h"
# include "../utils/cub_vec.h"

void			ray(t_vars *vars, t_img *img);
t_vec			get_collide_pos(t_trace trace);
t_mouseover		get_mouseover(t_vars *vars);
int				check_colide(t_vars *vars, t_vec pos);
void			render_portal(t_shape line, float offset, t_vars *vars);
t_ray			get_init_ray(t_rot *rot, double x, double y);
void			cast_forward(t_ray *ray, t_ray step);
t_img			*get_texture(t_vars *vars, t_cardinal card);

#endif
