#include <unistd.h>

void	ft_putnbr(int n)
{
	char digit;

	if (n > 9)
		ft_putnbr(n / 10);
	digit = n % 10 + 48;
	write (1, &digit, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	ft_putnbr(argc - 1);
	write (1, "\n", 1);
	return 0;
}
