/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:38 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:26:38 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	nb;
	int				len_nbr;

	len_nbr = ft_nbrlen(n);
	nbr = (char *)malloc(len_nbr + 1);
	if (nbr == 0)
		return (0);
	nbr[len_nbr] = 0;
	nb = n;
	if (n < 0)
		nb = -n;
	while (len_nbr--)
	{
		nbr[len_nbr] = "0123456789"[nb % 10];
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
