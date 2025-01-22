/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:26 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:27 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_path.h"

t_vec	*make_path(t_node *end)
{
	int		size;
	t_vec	*path;

	size = node_path_size(end);
	if (!end || size == 0)
		return (NULL);
	path = malloc(sizeof(t_vec) * (size + 1));
	if (!path)
		return (NULL);
	path[size].x = -999;
	path[size].y = -999;
	while (end)
	{
		path[--size] = end->pos;
		end = end->parent;
	}
	return (path);
}
