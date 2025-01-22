/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:53:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:53:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PLAYER_H
# define CUB_PLAYER_H

# include "../utils/cub_vec.h"
# include "../utils/cub_keybinds.h"
# include "cub_map.h"
# include "cub_collide.h"
# include "cub_portal.h"

t_player	make_player();
void		update_motion(t_player *player, t_vars *vars);
bool		should_bob(t_player *player);

#endif
