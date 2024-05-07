/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:06:55 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/18 18:22:26 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_check(char s, va_list *args, int *len)
{
	if (s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (s == 'u')
		ft_putunsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_puthex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_puthex(va_arg(*args, unsigned int), len, 'X');
	else if (s == 'p')
		ft_putptr(va_arg(*args, size_t), len);
	else if (s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (s == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_check(str[i], &args, &length);
		}
		else
		{
			if (write (1, &str[i], 1) < 0)
				return (-1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
/*
int	main(void)
{
	int	num = 42;
	char str[] = "Hola Mundo";

	ft_printf("Esto es un número: %d\n", num);
	ft_printf("Esto es un string: %s\n", str);

	return (0);
}*/