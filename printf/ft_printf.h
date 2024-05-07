/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:51:13 by ide-la-f          #+#    #+#             */
/*   Updated: 2023/12/13 11:46:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);
void	ft_puthex(unsigned int x, int *length, char x_or_x);
void	ft_putunsigned(unsigned int u, int *length);
void	ft_putptr(size_t pointer, int *length);
void	ft_putnbr(int number, int *length);
void	ft_putchar(char character, int *length);
void	ft_putstr(char *args, int *length);

#endif