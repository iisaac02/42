/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:29 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MAP_PARSER_H
# define CUB_MAP_PARSER_H

# include "../cub.h"
# include "cub_map_setter.h"
# include "../utils/cub_error.h"

t_vec	get_map_size(t_line *start);
int		set_map(t_vars *vars, char c, t_vec p);
void	handle_door_rotation(t_vars *vars);
bool	is_map_valid(t_map *map);

#endif
