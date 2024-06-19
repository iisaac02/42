/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:26:33 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:44 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, const char *base, size_t len_base)
{
	char			*nbr;
	size_t			len;
	unsigned int	nb;

	len = ft_nbrlen_base(n, len_base);
	nbr = (char *)malloc(len + 1);
	if (nbr == 0)
		return (0);
	nbr[len] = 0;
	nb = n;
	if (n < 0)
		nb = -n;
	while (len--)
	{
		nbr[len] = base[nb % len_base];
		nb /= len_base;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
