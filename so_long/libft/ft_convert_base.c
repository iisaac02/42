/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:25:39 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/06/11 12:37:44 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_base(
	const char *str, const char *base_from, const char *base_to)
{
	int				nb;

	nb = ft_atoi_base(str, base_from, ft_strlen(base_from));
	return (ft_itoa_base(nb, base_to, ft_strlen(base_to)));
}
