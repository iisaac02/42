/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:04 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/28 10:50:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[d->sia - 1];
	i = d->sia - 1;
	while (--i >= 0)
		d->sa[i + 1] = d->sa[i];
	d->sa[0] = temp;
}
