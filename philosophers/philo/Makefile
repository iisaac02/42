NAME = philo

SRC = main.c utils.c init.c threads.c monitor.c routine_actions.c

MANPATH = $(addprefix ./src/, $(SRC))

CC = clang

FLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address -g

HEADER = ./philo.h

DEF_COLOR =		\033[0;39m
RED =			\033[0;31m
GREEN =			\033[0;32m

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@$(CC) $(FLAGS) -o $(NAME) $(MANPATH)
	@echo "\n$(GREEN) Philosophers Created ✅$(DEF_COLOR)\n"

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)
	@echo "\n$(RED) Philosophers Removed ❌$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
