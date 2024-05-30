/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:28:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/30 10:24:35 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	check_args(char **argv, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (check_num(argv[i + 1]) == -1 || *argv[i + 1] == '\0')
			return (-1);
	}
	return (0);
}
