/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_collide.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:49:11 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:49:12 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_COLLIDE_H
# define CUB_COLLIDE_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "cub_map.h"
# include "cub_portal.h"

bool	collide_object(t_vars *vars, double x, double y, t_sprite *goomba);
void	collidex(t_vars *vars, t_player *player);
void	collidey(t_vars *vars, t_player *player);
void	add_nocollide(t_vars *vars, t_vecd *pos, t_vecd mov, t_sprite *s);

#endif
