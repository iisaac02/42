#include <unistd.h>

int	ft_atoi(char *str)
{
	int result = 0;
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

void	print_hex(int n)
{
	char base[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write (1, &base[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write (1, "\n", 1);
	return 0;
}
