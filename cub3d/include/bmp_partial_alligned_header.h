/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_partial_alligned_header.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:06:41 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:06:42 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_PARTIAL_ALLIGNED_HEADER_H
# define BMP_PARTIAL_ALLIGNED_HEADER_H

typedef struct				s_bmp_partial_alligned_header
{
	unsigned int			size;
	unsigned int			reserved;
	unsigned int			footer_offset;
	unsigned int			header_size;
	unsigned int			width;
	unsigned int			height;
	unsigned int			planes_bc;
	unsigned int			compression;
	unsigned int			images_size;
	unsigned int			x_res;
	unsigned int			y_res;
	unsigned int			colors_used;
	unsigned int			important_colors;
}							t_bmp_partial_alligned_header;

#endif
