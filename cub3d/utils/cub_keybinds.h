/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keybinds.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:55:00 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 19:30:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_KEYBINDS_H
# define CUB_KEYBINDS_H

# include "cub_vec.h"
# include "../cub.h"
# include "../render/cub_raycast.h"
# include "cub_cleaner.h"
# include <stdbool.h>

#  define ROTATE_LEFT 0xff51
#  define ROTATE_RIGHT 0xff53
#  define ROTATE_UP 0xff52
#  define ROTATE_DOWN 0xff54
#  define FORWARD_W_Z 0x0077
#  define BACK_S_S 0x0073
#  define RIGHT_D_D 0x0064
#  define LEFT_A_Q 0x0061
#  define JUMP_SPACE 0x0020
#  define SNEAK_MAJ 0xffe1
#  define MAKE_PORTAL 0xff0d
#  define ESC 0xff1b

void			set_keystate(t_keybinds *keybinds, int key, bool pressed);
int				key_press(int keycode, t_vars *vars);
int				key_lift(int keycode, t_vars *vars);
void			update_keybinds(t_vars *vars);
t_keybinds		make_keybinds();

#endif
