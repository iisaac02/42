/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:55:18 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:55:19 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ROT_H
# define CUB_ROT_H

# include <math.h>

typedef struct	s_rot
{
	double		angle;
	double		cos;
	double		sin;
}				t_rot;

t_rot			make_rot(double angle);

#endif
