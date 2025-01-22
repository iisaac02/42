/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_cardinal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:21 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:43:22 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_CARDINAL_H
# define CUB_CARDINAL_H

# include "../render/cub_raycast.h"

t_cardinal	get_cardinal(t_trace trace);
t_cardinal	get_opposite(t_cardinal card);
t_vec		get_direction(t_cardinal card);

#endif
