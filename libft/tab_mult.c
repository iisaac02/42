#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
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

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	main(int argc, char **argv)
{
	int	i;
	int nbr;

	if (argc != 2)
		write (1, "\n", 1);
	else
	{
		i = 1;
		nbr = ft_atoi(argv[1]);

		while (i <= 9)
		{
			ft_putnbr(i);
			write (1, " x ", 3);
			ft_putnbr(nbr);
			write (1, " = ", 3);
			ft_putnbr(i * nbr);
			write (1, "\n", 1);
			i++;
		}
	}
	return 0;
}
