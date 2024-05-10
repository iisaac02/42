#include <unistd.h>

int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return sign * result;
}

int	is_prime(int num)
{
	int	i = 2;

	if (num <= 1)
		return 0;
	while (i * i <= num)
	{
		if (num % i == 0)
			return 0;
		i++;
	}
	return 1;
}

void	ft_putnbr(int n)
{
	char digit;

	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + '0';
	write (1, &digit, 1);
}

int	main(int argc, char **argv)
{
	int nbr;
	int sum;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		sum = 0;

		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		ft_putnbr(sum);
	}
	else
		write (1, "0", 1);
	write (1, "\n", 1);
	return 0;
}
