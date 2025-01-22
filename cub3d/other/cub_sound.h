/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sound.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:08:53 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:08:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SOUND_H
# define CUB_SOUND_H

# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

typedef struct	s_sounds
{
	uint32_t	door;
	uint32_t	hurt;
	uint32_t	stomp;
	uint32_t	portal;
	uint32_t	heal;
	uint32_t	ambient;
	uint32_t	walk;
}				t_sounds;

void			init_sound_empty(t_sounds *sounds);
void			clear_sounds(t_sounds *sounds);
bool			load_sound(uint32_t *s, char *path);
void			play_sound(uint32_t s);
void			play_sound_alt(uint32_t s, bool play, bool loop);

#endif
