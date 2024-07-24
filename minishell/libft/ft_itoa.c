/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiturria <aiturria@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:11:12 by aiturria          #+#    #+#             */
/*   Updated: 2023/12/10 11:42:40 by aiturria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int	ft_counter(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		counter++;
	}
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_minimumint(void)
{
	char	*minimum;
	char	*last;
	int		i;

	i = 0;
	last = "-2147483648";
	minimum = (char *)malloc(sizeof(char) * 12);
	if (!minimum)
		return (NULL);
	while (last[i])
	{
		minimum[i] = last[i];
		i++;
	}
	minimum[i] = '\0';
	return (minimum);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		counter;
	int		i;

	if (n == -2147483648)
		return (ft_minimumint());
	counter = ft_counter(n);
	number = (char *)malloc(sizeof(char) * (counter + 1));
	if (!number)
		return (NULL);
	number[counter] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	i = counter - 1;
	while (i >= 0 && n > 9)
	{
		number[i--] = n % 10 + '0';
		n /= 10;
	}
	number[i] = n + '0';
	return (number);
}

/*int	main(void)
{
	printf("%s", ft_itoa(6));
	return (0);
}*/
