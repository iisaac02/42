/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:19 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:20 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_FILE_H
# define CUB_FILE_H

# include "../utils/cub_error.h"
# include "cub_parser.h"
# include "cub_map_parser.h"
# include "../cub.h"

int	load_f(char *filepath, t_vars *vars);

#endif
