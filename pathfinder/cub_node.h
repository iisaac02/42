/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:11:15 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:16 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_NODE_H
# define CUB_NODE_H

# include "../utils/cub_vec.h"
# include <stdlib.h>

typedef struct s_node	t_node;

struct		s_node
{
	t_vec	pos;
	t_node	*parent;
	int		square_dist;
	t_node	*next;
};

void		node_remove(t_node **begin_list, t_node *node);
void		node_push(t_node **begin_list, t_node *node);
void		node_sort(t_node **begin_list);
t_node		*find_node(t_node *cur, t_vec pos);
int			node_path_size(t_node *end);
void		node_insert(t_node **begin_list, t_node *node);
t_node		*make_node(t_node *parent, t_vec end, t_vec pos);

#endif
