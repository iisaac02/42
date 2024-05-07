/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:17 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/06 17:44:55 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (-2147483648 == n)
	{
		write (fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
		}
		if (n / 10 > 0)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		c = '0' + n % 10;
		write (fd, &c, 1);
	}
}
/*
int	main(void)
{
	int	n = 4;
	int	fd = 1;

	ft_putnbr_fd(n, fd);
	return (0);
}*/