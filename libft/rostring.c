#include <unistd.h>

void	write_word(char *start, char *end)
{
	while (start < end)
	{
		write (1, start, 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*start;
	char	*end;

	if (argc > 1)
	{
		str = argv[1];
		while (*str == ' ' || *str == '\t')
			str++;
		start = str;
		while (*str && *str != ' ' && *str != '\t')
			str++;
		end = str;
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str)
		{
			while (*str)
			{
				if (*str == ' ' || *str == '\t')
				{
					while (*str == ' ' || *str == '\t')
						str++;
					if (*str)
						write (1, " ", 1);
				}
				else
				{
					write (1, str, 1);
					str++;
				}
			}
			write (1, " ", 1);
		}
		write_word(start, end);
	}
	write (1, "\n", 1);
	return 0;
}
