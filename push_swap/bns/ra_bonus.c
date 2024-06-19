/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:29:48 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/28 10:50:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[0];
	i = -1;
	while (++i < (d->sia - 1))
		d->sa[i] = d->sa[i + 1];
	d->sa[d->sia - 1] = temp;
}