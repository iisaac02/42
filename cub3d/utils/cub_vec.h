/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:04 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:04:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_VEC_H
# define CUB_VEC_H

# include <math.h>

typedef struct	s_vec
{
	int			x;
	int			y;
}				t_vec;

typedef struct	s_vecd
{
	double		x;
	double		y;
}				t_vecd;

typedef struct	s_vec3d
{
	double		x;
	double		y;
	double		z;
}				t_vec3d;

void			normalize(t_vecd *vec, double scale);
double			calc_sqrtlen(t_vecd v);
double			square_dist(t_vec3d start, t_vecd end);
double			square_dist_mid(t_vec3d start, t_vecd end);
double			distancemid2(t_vecd start, t_vecd end);
int				square_dist2i(t_vec start, t_vec end);
int				dist2di(t_vecd start, t_vec end);

#endif
