/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:59:46 by aiturria          #+#    #+#             */
/*   Updated: 2024/07/11 12:18:27 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				minus;
	long long int	result;

	result = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LLONG_MAX - (*str - '0')) / 10)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * minus);
}

/*int	ft_atoi(const char *str)
{
	int				minus;
	long long int	result;
	result = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	result = result * minus;
	if (result > LONG_MAX || result < LONG_MIN)
		return (0);
	return (result);
*/
