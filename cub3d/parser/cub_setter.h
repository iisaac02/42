/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_setter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:10:00 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:10:01 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_SETTER_H
# define CUB_SETTER_H

# include "../cub.h"
# include "../utils/cub_error.h"

void	set_resolution(t_vars *vars, char *input);
void	set_texture(t_img *img, t_vars *vars, char *path);
void	set_color(t_vars *vars, int *val, char *input);
void	set_sound(uint32_t *s, t_vars *vars, char *path);

#endif
