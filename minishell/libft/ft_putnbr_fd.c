/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:01:58 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:55:00 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		div;

	div = 1;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n = -n;
	}
	while (n / div > 9)
		div *= 10;
	while (div != 0)
	{
		a = n / div + '0';
		write(fd, &a, 1);
		n %= div;
		div /= 10;
	}
}
/*#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
}*/
