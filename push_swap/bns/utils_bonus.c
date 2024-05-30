/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:30:37 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/05/28 11:25:29 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	ft_free(t_list *d, int print)
{
	if (d->sa)
	{
		free(d->sa);
	}
	if (d->sb)
	{
		free(d->sb);
	}
	if (d)
	{
		free(d);
	}
	if (print == 0)
		write (2, "Error\n", 6);
	exit (0);
}

static int	ft_error(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}

int	ft_atoi(const char *str, t_list *d)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
		if (result > ((long long int)INT_MAX + 1) && sign == -1)
			return (ft_error(d, result));
		if (result > INT_MAX && sign == 1)
			return (ft_error(d, result));
	}
	return (result * sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (0);
	if (start > ft_strlen(str))
	{
		res = malloc(1);
		if (!res)
			return (0);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(str) - start < len)
		len = ft_strlen(str) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (start < ft_strlen(str) && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
