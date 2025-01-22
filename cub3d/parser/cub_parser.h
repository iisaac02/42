/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:48 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:49 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARSER_H
# define CUB_PARSER_H

# include "../cub.h"
# include "cub_setter.h"
# include "../render/cub_texture.h"

bool	read_argument_sounds(t_vars *vars, t_line *file);
bool	read_argument_custom(t_vars *vars, t_line *file);
bool	read_argument(t_vars *vars, t_line *file);

#endif
