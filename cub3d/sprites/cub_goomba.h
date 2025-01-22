/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_goomba.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:56:34 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_GOOMBA_H
# define CUB_GOOMBA_H

# include "../cub.h"
# include "../world/cub_collide.h"
# include "cub_sprite_list.h"
# include "cub_doors.h"
# include "../pathfinder/cub_astar.h"

void	handle_goomba(t_sprite *curr, t_vars *vars);

#endif
