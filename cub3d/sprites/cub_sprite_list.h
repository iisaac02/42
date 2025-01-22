/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:41 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:56:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_LIST_H
# define CUB_SPRITE_LIST_H

# include "../cub.h"

void		swap_sprite(t_sprite **prevnext, t_sprite *last);
void		sprite_sort(t_vars *vars, t_sprite **begin_list);
t_sprite	*make_sprite(t_vecd pos, t_sprite_k kind, t_img *img);
t_sprite	*sprite_pf(t_sprite **begin_list, t_vecd pos,
				t_sprite_k kind, t_img *img);
void		empty_sprites(t_sprite **begin_list);

#endif
