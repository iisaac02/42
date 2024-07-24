/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:14 by aiturria          #+#    #+#             */
/*   Updated: 2024/02/11 13:57:42 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	ft_putcharr(int format)
{
	if (write(1, &format, 1) < 0)
		return (-1);
	return (1);
}

int	ft_putstring(char *format)
{
	int	len;

	len = 0;
	if (!format)
		format = "(null)";
	while (format && format[len])
	{
		if (ft_putcharr(format[len]) < 0)
			return (-1);
		len++;
	}
	return (len);
}

int	ft_specifier(va_list arg, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putcharr(va_arg(arg, int));
	else if (format == 's')
		len = ft_putstring(va_arg(arg, char *));
	else if (format == 'p')
		len = ft_putpointer(va_arg(arg, uintptr_t));
	else if (format == 'd' || format == 'i')
		len = ft_putint(va_arg(arg, int));
	else if (format == 'u')
		len = ft_putunsigint(va_arg(arg, unsigned int));
	else if (format == 'x')
		len = ft_puthexadem(va_arg(arg, unsigned int), 'x');
	else if (format == 'X')
		len = ft_puthexadem(va_arg(arg, unsigned int), 'X');
	else if (format == '%')
		len = ft_putcharr('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		check;

	va_start(arg, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = ft_specifier(arg, *++format);
			if (check < 0)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, format, 1) < 0)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(arg);
	return (len);
}
