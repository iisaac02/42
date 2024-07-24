/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:09:29 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/22 16:14:53 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"

static int	ft_minimumint(void)
{
	if (ft_putstring("-2147483648") < 0)
		return (-1);
	return (11);
}

int	ft_putint(int n)
{
	int		div;
	int		len;

	div = 1;
	len = 0;
	if (n == -2147483648)
		return (ft_minimumint());
	if (n < 0)
	{
		if (ft_putcharr('-') < 0)
			return (-1);
		n = -n;
		len++;
	}
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		if (ft_putcharr(n / div + '0') < 0)
			return (-1);
		n %= div;
		div /= 10;
		len++;
	}
	return (len);
}

int	ft_putunsigint(unsigned int n)
{
	int		div;
	int		len;

	div = 1;
	len = 0;
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		if (ft_putcharr(n / div + '0') < 0)
			return (-1);
		n %= div;
		div /= 10;
		len++;
	}
	return (len);
}
