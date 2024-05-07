CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= server.c client.c
SRCSBONUS = server_bonus.c client_bonus.c
OBJS 	= $(SRCS:.c=.o)
OBJSBONUS	= $(SRCSBONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "Compilando\n"
	@ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

all: $(NAME) $(OBJS) $(OBJSBONUS)

bonus: $(OBJSBONUS)
	@ar rcs $(NAME) $(OBJSBONUS)

clean:
	@printf "Eliminando\n"
	@rm -f $(OBJS)
	@rm -f $(OBJSBONUS)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@rm -f $(OBJSBONUS)

re: clean all

.PHONY: all clean re