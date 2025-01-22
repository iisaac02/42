/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_astar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:10:29 by ide-la-f          #+#    #+#             */
/*   Updated: 2025/01/22 18:10:30 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_astar.h"

t_node	*add_node(t_astar *star, t_node *parent, t_vec new)
{
	t_node	*newnode;

	if (star->closed_map[star->map->size.x * new.y + new.x])
		return (NULL);
	newnode = make_node(parent, star->end_pos, new);
	if (star->end_pos.x == new.x && star->end_pos.y == new.y)
		return (newnode);
	node_insert(&star->list_open, newnode);
	star->closed_map[star->map->size.x * new.y + new.x] = 1;
	return (NULL);
}

bool	is_valid(t_map *map, t_vec pos)
{
	int val;

	if (pos.x < 0 || pos.y < 0)
		return (false);
	if (pos.x >= map->size.x || pos.y >= map->size.y)
		return (false);
	val = map_get_val(map, pos.x, pos.y);
	return (!(val == MAP_BLOCK || val == MAP_NOENTRY));
}

void	add_neighbors(t_astar *star, t_node *cur)
{
	int		i;
	t_vec	pos;
	t_node	*next;

	while (cur)
	{
		next = cur->next;
		node_remove(&star->list_open, cur);
		node_push(&star->list_closed, cur);
		i = 0;
		while (i < 4)
		{
			pos = get_neighbor(i++, cur->pos);
			if (is_valid(star->map, pos))
			{
				star->goal = add_node(star, cur, pos);
				if (star->goal)
					return ;
			}
		}
		cur = next;
	}
}

void	clear_list(t_astar *star, t_node *a, t_node *b, t_node *goal)
{
	t_node *t;

	while (a)
	{
		t = a->next;
		free(a);
		a = t;
	}
	while (b)
	{
		t = b->next;
		free(b);
		b = t;
	}
	free(star->closed_map);
	free(goal);
}

t_vec	*astar(t_map *map, t_vec start, t_vec end, unsigned int maxtries)
{
	t_astar star;
	t_vec	*path;

	if (!is_valid(map, start) || !is_valid(map, end) ||
		!(star.closed_map = make_closedmap(map->size.x * map->size.y)))
		return (NULL);
	star.start_pos = start;
	star.end_pos = end;
	star.list_open = make_node(NULL, end, start);
	star.list_closed = NULL;
	star.goal = NULL;
	star.map = map;
	while (maxtries--)
	{
		if (!star.list_open)
			break ;
		add_neighbors(&star, star.list_open);
		if (star.goal)
			break ;
	}
	path = make_path(star.goal);
	clear_list(&star, star.list_open, star.list_closed, star.goal);
	return (path);
}
