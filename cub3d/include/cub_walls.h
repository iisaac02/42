/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_walls.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:43 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:44 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_WALLS_H
# define CUB_WALLS_H

typedef struct		s_walls
{
	t_img			north;
	t_img			south;
	t_img			east;
	t_img			west;
}					t_walls;

#endif
