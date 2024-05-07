
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= ft_printf.c ft_putchar.c ft_putnbr.c ft_puthex.c ft_putptr.c \
		ft_putstr.c ft_putunsigned.c
OBJS 	= $(SRCS:.c=.o)
INCLUDES	= ft_printf.h
NAME	= libftprintf.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDES)
	@printf "Compilando las cozitas\n"
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@printf "Eliminando las cozitas compiladas\n"
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re