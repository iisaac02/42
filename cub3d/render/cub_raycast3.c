/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_raycast3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:58:40 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:58:41 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_raycast.h"

void	cast_forward(t_ray *ray, t_ray step)
{
	if (ray->ln_cos < ray->ln_sin)
	{
		ray->st_cos.x += step.st_cos.x;
		ray->st_cos.y += step.st_cos.y;
		ray->ln_cos += step.ln_cos;
	}
	else
	{
		ray->st_sin.x += step.st_sin.x;
		ray->st_sin.y += step.st_sin.y;
		ray->ln_sin += step.ln_sin;
	}
}
