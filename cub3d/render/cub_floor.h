/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_floor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:32 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:57:33 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FLOOR_H
# define CUB_FLOOR_H

# include "../cub.h"

void	setup_floor(t_vars *vars, t_floor_render *f);
void	draw_floor(t_vars *vars);
void	render_row_floor(t_vars *vars, t_floor_render *f);

#endif
