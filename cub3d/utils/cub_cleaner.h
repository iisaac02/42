/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cleaner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:54:42 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:54:43 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CLEANER_H
# define CUB_CLEANER_H

# include "../cub.h"
# include "../sprites/cub_sprites.h"
# include "cub_line_reader.h"

void	destroy_img(t_vars *vars, t_img *img);
void	clean_images(t_vars *vars);
void	clean_all(t_vars *vars);
void	clean_and_exit(int code, t_vars *vars);
int		clean_and_exit_z(t_vars *vars);
int		mlx_destroy_display(void *mlx_ptr);

#endif
