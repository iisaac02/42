
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memset.c ft_strchr.c \
		  ft_memmove.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		  ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		  ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
OBJS 	= $(SRCS:.c=.o)
OBJSBN	= $(SRCSBONUS:.c=.o)
NAME 	= libft.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "Compilando mis cozitas\n"
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJSBN) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(OBJSBN)

clean:
	@printf "Eliminando las cozitas compiladas\n"
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(OBJS)

re: clean all

.PHONY: all clean re