/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_sound.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:08:28 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:08:29 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_sound.h"

void	init_sound_empty(t_sounds *sounds)
{
	sounds->door = 0;
	sounds->hurt = 0;
	sounds->stomp = 0;
	sounds->portal = 0;
	sounds->heal = 0;
	sounds->ambient = 0;
	sounds->walk = 0;
}

void	clear_sounds(t_sounds *sounds)
{
	(void)sounds;
}

bool	load_sound(uint32_t *s, char *path)
{
	(void)s;
	(void)path;
	return (false);
}

void	play_sound_alt(uint32_t s, bool play, bool loop)
{
	(void)s;
	(void)play;
	(void)loop;
}

void	play_sound(uint32_t s)
{
	(void)s;
}
