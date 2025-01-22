/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:10:46 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:02 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_node.h"

t_node	*make_node(t_node *parent, t_vec end, t_vec pos)
{
	t_node *elem;

	if (!(elem = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	elem->pos = pos;
	elem->parent = parent;
	elem->next = NULL;
	elem->square_dist = square_dist2i(end, pos);
	return (elem);
}

int		node_path_size(t_node *end)
{
	int i;

	i = 0;
	while (end)
	{
		++i;
		end = end->parent;
	}
	return (i);
}

void	node_remove(t_node **begin_list, t_node *node)
{
	t_node *prev;
	t_node *aftr;

	prev = NULL;
	aftr = *begin_list;
	while (aftr)
	{
		if (aftr == node)
		{
			if (prev == NULL)
				*begin_list = aftr->next;
			else
				prev->next = aftr->next;
			break ;
		}
		prev = aftr;
		aftr = prev->next;
	}
}

void	node_push(t_node **begin_list, t_node *node)
{
	node->next = *begin_list;
	*begin_list = node;
}

void	node_insert(t_node **begin_list, t_node *node)
{
	t_node *last;
	t_node *prev;

	last = *begin_list;
	node->next = NULL;
	if (!last || (prev = NULL))
	{
		*begin_list = node;
		return ;
	}
	while (last)
	{
		if (last->square_dist > node->square_dist)
		{
			if (prev)
				prev->next = node;
			else
				*begin_list = node;
			node->next = last;
			return ;
		}
		prev = last;
		last = last->next;
	}
	prev->next = node;
}
