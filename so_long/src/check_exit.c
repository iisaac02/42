/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:37:29 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/15 09:37:03 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "Congratulations, you have won! 🥳🏆\n", 34);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write (1, "You need to catch all collectables!\n", 36);
		return (1);
	}
	else
		return (0);
}
