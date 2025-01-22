/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_setter.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_SETTER_H
# define CUB_MAP_SETTER_H

# include "../cub.h"
# include "../world/cub_player.h"
# include "../utils/cub_error.h"
# include "../sprites/cub_sprites.h"

int		set_player(t_vars *vars, char c, t_vec p);
int		set_sprite(t_vars *vars, char c, t_vec p);
int		set_entity(t_vars *vars, char c, t_vec p);
int		set_pathfinder(t_vars *vars, char c, t_vec p);

#endif
