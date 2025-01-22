/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bitmap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:57:03 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:57:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BITMAP_H
# define CUB_BITMAP_H

# include "../cub.h"

t_bmp_partial_alligned_header	get_generic_header(int width, int height);
void							*bad_bzero(void *o, size_t len);
int								render_and_save(t_vars *vars);

#endif
