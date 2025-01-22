/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_star_cardinal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:12:00 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STAR_CARDINAL_H
# define CUB_STAR_CARDINAL_H

# include "../utils/cub_vec.h"
# include "cub_node.h"
# include "../world/cub_map.h"
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>

t_vec	get_neighbor(int rot, t_vec origin);
bool	is_empty(t_map *map, t_node *start, t_node *end);
bool	is_in_map(t_map *map, t_vec pos);

#endif
