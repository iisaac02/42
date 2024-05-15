/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:49:23 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/15 09:35:43 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error2(t_list *d, int num)
{
	d->moves++;
	d->moves--;
	if (num == 8)
		write (1, "The map contain an error character\n", 35);
	if (num == 9)
		write (1, "The map is not rectangular\n", 27);
}

void	ft_error(t_list *d, int num)
{
	write(1, "❌ERROR❌\n", 12);
	if (num > 7)
		ft_error2(d, num);
	if (num == 1)
		write (1, "In the begin of the line there is not a wall\n", 45);
	if (num == 2)
		write (1, "In the final of the line there is not a wall\n", 45);
	if (num == 3)
		write (1, "In the first line there is not a wall\n", 38);
	if (num == 4)
		write (1, "In the last line there is not a wall\n", 37);
	if (d->consum < 1 && num == 5)
		write (1, "There are not collectables\n", 27);
	if (d->player != 1 && num == 5)
		write (1, "The map must contain 1 player only\n", 35);
	if (d->ex < 1 && num == 5)
		write (1, "The map must have 1 exit\n", 25);
	if (num == 6)
		write (1, "The folder haven´t the correct extension\n", 41);
	if (num == 7)
		write (1, "The map is not rectangular\n", 27);
	ft_free(d);
}
