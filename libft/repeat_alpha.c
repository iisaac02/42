#include <unistd.h>

void	ft_putchar(char c, int i)
{
	while (i--)
	{
		write (1, &c, 1);
	}
}

void	repeat_alpha(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			ft_putchar(*str, *str - 'a' + 1);
		else if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str, *str - 'A' + 1);
		else
			write (1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write (1, "\n", 1);
	return 0;
}
