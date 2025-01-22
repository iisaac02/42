/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_mouseover_struct.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:03 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:07:04 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MOUSEOVER_STRUCT_H
# define CUB_MOUSEOVER_STRUCT_H

typedef struct		s_mouseover
{
	bool			found;
	t_vec			pos;
	t_cardinal		card;
}					t_mouseover;

#endif
