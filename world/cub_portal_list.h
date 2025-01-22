/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_portal_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:54:03 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 17:54:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PORTAL_LIST_H
# define CUB_PORTAL_LIST_H

# include "../cub.h"
# include "cub_cardinal.h"
# include <stdlib.h>

t_portal_render	*make_portal_render(t_shape line, float offset);
void			portal_render_pf(t_portal_render **begin_list, t_shape line,
					float offset);
void			portal_foreach_free(t_portal_render *begin_list,
					void (*f)(t_shape, float, t_vars*), t_vars *vars);

#endif
