/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:53:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:54:00 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_portal_list.h"

t_portal_render	*make_portal_render(t_shape line, float offset)
{
	t_portal_render *elem;

	if (!(elem = malloc(sizeof(t_portal_render))))
		return (NULL);
	elem->line = line;
	elem->offset = offset;
	elem->next = NULL;
	return (elem);
}

void			portal_render_pf(t_portal_render **begin_list, t_shape line,
					float offset)
{
	t_portal_render *first;

	if (!(first = make_portal_render(line, offset)))
		return ;
	first->next = *begin_list;
	*begin_list = first;
}

void			portal_foreach_free(t_portal_render *begin_list,
					void (*f)(t_shape, float, t_vars*), t_vars *vars)
{
	t_portal_render *last;
	t_portal_render *next;

	last = begin_list;
	while (last)
	{
		f(last->line, last->offset, vars);
		next = last->next;
		free(last);
		last = next;
	}
}
