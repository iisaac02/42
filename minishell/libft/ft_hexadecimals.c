/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:29:15 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/22 16:14:56 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "libft.h"

static int	ft_puthexabase(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
		len = ft_puthexabase(nbr / 16, base);
	if (len < 0)
		return (-1);
	if (ft_putcharr(base[nbr % 16]) < 0)
		return (-1);
	return (++len);
}

/* static int	ft_puthexabase(long unsigned int nbr, char *base)
{
	int		len;
	int		i;
	char	hexastring[200];

	len = 0;
	i = 0;
	while (nbr != 0)
	{
		hexastring[i++] = base[nbr % 16];
		nbr /= 16;
	}
	while (i--)
	{
		if (ft_putcharr(hexastring[i]) < 0)
			return (-1);
		len++;
	}
	return (len);
} */

int	ft_putpointer(uintptr_t pointer)
{
	int			len;
	char		*base;

	len = 0;
	base = "0123456789abcdef";
	if (ft_putstring("0x") < 0)
		return (-1);
	if (pointer == 0)
	{
		ft_putcharr('0');
		return (3);
	}
	len = ft_puthexabase(pointer, base);
	if (len < 0)
		return (-1);
	return (len + 2);
}

int	ft_puthexadem(unsigned int pointer, char letter)
{
	int					len;
	char				*base;

	len = 0;
	if (pointer == 0)
		return (ft_putcharr('0'));
	if (letter == 'x')
		base = "0123456789abcdef";
	if (letter == 'X')
		base = "0123456789ABCDEF";
	len = ft_puthexabase(pointer, base);
	if (len < 0)
		return (-1);
	return (len);
}

/* int	main(void)
{
    //int x = 9534;
    //int *ptr = &x;

    //printf("\n%d", ft_putpointer((uintptr_t) ptr));
	printf("\n%d", ft_puthexadem((unsigned int)9223372036854775807LL, 'x'));
	printf("\n%x", (unsigned int)9223372036854775807LL);
	return (0);
}
 */