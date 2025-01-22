/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_astar.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:10:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:10:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ASTAR_H
# define CUB_ASTAR_H

# include "cub_node.h"
# include "cub_star_cardinal.h"
# include "cub_path.h"
# include "../utils/cub_vec.h"
# include "../utils/cub_utils.h"
# include "../world/cub_map.h"
# include <unistd.h>

typedef struct s_astar	t_astar;
struct			s_astar
{
	t_node		*list_open;
	t_node		*list_closed;
	t_node		*goal;
	t_vec		start_pos;
	t_vec		end_pos;
	t_map		*map;
	char		*closed_map;
};

t_vec			*astar(t_map *map, t_vec start, t_vec end,
					unsigned int maxtries);

#endif
