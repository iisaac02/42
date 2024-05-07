/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:47:59 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/02/13 18:10:07 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf/libft/libft.h"

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putchar (('0' + num));
}

void	conv_txt(char *s)
{
	int		i;
	int		base;
	char	bit;
	int		control;
	int		resultado;

	i = 7;
	while (s[i])
	{
		base = 1;
		control = i;
		resultado = 0;
		while (base <= 128)
		{
			bit = s[control];
			if (bit == '1')
				resultado = resultado + base;
			base = base * 2;
			control--;
		}
		write(1, &resultado, 1);
		i = i + 8;
	}
}

void	alm_bin(int sig)
{
	static int	i = 0;
	static char	c[8];

	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		i = 0;
		conv_txt(c);
	}
}

int	main(void)
{
	write (1, "PID: ", 5);
	getpid();
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, alm_bin);
	signal(SIGUSR2, alm_bin);
	while (1)
		sleep(1);
	return (0);
}
