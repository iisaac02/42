/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:13 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:14 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_STRUCT_H
# define CUB_PORTAL_STRUCT_H

typedef struct				s_portal_render
{
	t_shape					line;
	float					offset;
	struct s_portal_render	*next;
}							t_portal_render;

typedef struct				s_portal
{
	t_vec					pos;
	t_cardinal				card;
	struct s_portal			*link;
}							t_portal;

#endif
