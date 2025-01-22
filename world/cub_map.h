/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:53:46 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 19:09:23 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_H
# define CUB_MAP_H

# define MAP_EMPTY 10
# define MAP_AIR 0
# define MAP_BLOCK 1
# define MAP_NOENTRY 2

# include <stdlib.h>
# include "../utils/cub_vec.h"

typedef struct		s_map
{
	t_vec			size;
	int				buf_size;
	unsigned char	*data;
}					t_map;

t_map				make_empty(t_vec size);
void				map_set(t_map *map, int x, int y, int value);
int					map_get(t_map *map, int x, int y);
int					map_get_val(t_map *map, int x, int y);
void				clear_map(t_map *map);
#endif
