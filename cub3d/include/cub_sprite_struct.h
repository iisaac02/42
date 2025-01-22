/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sprite_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:24 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:25 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SPRITE_STRUCT_H
# define CUB_SPRITE_STRUCT_H

# include "cub_sprite_type.h"

typedef struct		s_sprite
{
	t_sprite_k		kind;
	t_vecd			pos;
	t_img			*texture;
	int				last_hurt;
	bool			dead;
	int				path_index;
	t_vec			*path;
	struct s_sprite	*next;
}					t_sprite;

#endif
