/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_texture.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:58:56 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_TEXTURE_H
# define CUB_TEXTURE_H

# include "../cub.h"
# include "../utils/cub_cleaner.h"

t_img	make_skybox(t_vars *vars, t_img *img, char *path);
t_img	make_gun(t_vars *vars, t_img *img, char *path);
t_img	make_dash(t_vars *vars, t_img *img, char *path);

#endif
