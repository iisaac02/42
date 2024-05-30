/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:34:08 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/29 10:06:34 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

static int	hargve_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nbstr_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		nb_zeros += arg_is_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (hargve_duplicates(argv))
		return (0);
	return (1);
}
