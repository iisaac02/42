#include <unistd.h>

void	ft_write(int n)
{
	char	str[10] = "0123456789";

	if (n > 9)
		ft_write(n / 10);
	write (1, &str[n % 10], 1);
}

int	main(void)
{
	int	i = 1;

	while (i <= 100)
	{
		if (i % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_write (i);
		write (1, "\n", 1);
		i++;
	}
	return 0;
}
