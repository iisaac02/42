/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bitmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:58 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:59:21 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bitmap.h"

t_bmp_partial_alligned_header	get_generic_header(int width, int height)
{
	t_bmp_partial_alligned_header	h;
	int								size;

	size = 54;
	bad_bzero(&h, sizeof(t_bmp_partial_alligned_header));
	h.width = width;
	h.height = height;
	h.planes_bc = 0x00180001;
	h.size = size + (3) * (width * height);
	h.footer_offset = size;
	h.header_size = size - 14;
	return (h);
}

void							*bad_bzero(void *o, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)o;
	while (i < len)
		dst[i++] = 0;
	return (o);
}

int								render_and_save(t_vars *vars)
{
	t_bmp_partial_alligned_header	header;
	t_vec							pos;
	int								color;
	int								fd;

	render_next_frame(vars);
	fd = open("./render.bmp", O_WRONLY | O_CREAT, 0666);
	header = get_generic_header(vars->resx, vars->resy);
	write(fd, "BM", 2);
	write(fd, &header, 52);
	pos.y = vars->resy;
	while (--pos.y >= 0)
	{
		pos.x = 0;
		while (pos.x < vars->resx)
		{
			color = get_pixel(&vars->img, pos.x++, pos.y);
			write(fd, &color, 3);
		}
		color = 0;
		write(fd, &color, (4 - ((int)vars->resx * 3) % 4) % 4);
	}
	return (1);
}
