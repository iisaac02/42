/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:54:51 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:54:52 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_ERROR_H
# define CUB_ERROR_H

# include "../cub.h"
# include "cub_cleaner.h"

void	handle_error(t_vars *vars, char *error, char *trace);
void	handle_warning(t_vars *vars, char *error);

#endif
