/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_blur.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:17 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:57:18 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BLUR_H
# define CUB_BLUR_H

# include "../utils/cub_utils.h"

typedef struct	s_blur
{
	void		*mlx;
	t_img		src;
	t_img		temp;
	t_img		dest;
	t_shape		shape;
	int			opt;
	int			x;
	int			y;
	int			i;
	double		kernel[21];
	int			kernel_size;
}				t_blur;

t_img			make_blur(t_img *data, void *mlx, bool yb);
t_blur			make_blur_struct(void *mlx, t_img orig, t_shape shape);
t_img			make_blur_opt(t_blur blur, bool yb);

#endif
