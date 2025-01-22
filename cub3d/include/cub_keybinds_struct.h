/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:06:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:00 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_STRUCT_H
# define CUB_KEYBINDS_STRUCT_H

# include "../utils/cub_vec.h"

typedef struct		s_keybinds
{
	bool			forwards;
	bool			backwards;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	bool			rotate_up;
	bool			rotate_down;
	bool			jump;
	bool			sneak;
	t_vecd			move;
}					t_keybinds;

#endif
