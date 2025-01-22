/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:55:14 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:55:15 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_rot.h"

t_rot	make_rot(double angle)
{
	t_rot rot;

	rot.angle = angle;
	rot.cos = cos(rot.angle);
	rot.sin = sin(rot.angle);
	return (rot);
}
