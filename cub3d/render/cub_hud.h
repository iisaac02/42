/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hud.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:46 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 20:36:29 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HUD_H
# define CUB_HUD_H

# include "../cub.h"
# include "cub_minimap.h"
# include "cub_xquartz_layer.h"

void	draw_hud(t_vars *vars);
void	draw_death(t_vars *vars);
void	draw_cursor(t_vars *vars);
void	render_hand(t_vars *vars);
void	draw_skybox(t_vars *vars);

#endif
