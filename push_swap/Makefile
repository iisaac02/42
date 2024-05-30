NAME = push_swap

NAME_BONUS = checker

DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

SRCS = ./src/cost.c ./src/swap.c ./src/do_move.c ./src/initialization.c \
			./src/push.c ./src/reverse_rotate.c ./src/rotate.c \
			./src/sort_tiny.c ./src/input_check_utils.c ./src/input_check.c \
			./src/main.c ./src/position.c ./src/sort.c ./src/stack.c ./src/utils.c

BONUS_SRC = ./bns/checker_bonus.c ./bns/ss_bonus.c ./bns/sa_bonus.c ./bns/sb_bonus.c ./bns/pa_bonus.c \
				./bns/rb_bonus.c ./bns/rr_bonus.c ./bns/rra_bonus.c ./bns/rrb_bonus.c ./bns/rrr_bonus.c ./bns/swap_bonus.c \
				./bns/get_next_line_bonus.c ./bns/checker_lines_bonus.c ./bns/check_same_nums_bonus.c \
				./bns/utils_bonus.c ./bns/check_args_bonus.c ./bns/pb_bonus.c ./bns/ra_bonus.c \

INCLUDE = ./inc/push_swap.h

INCLUDE_BONUS = ./inc/push_swap_bonus.h

CC = clang
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRC:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS2 = $(addsuffix .d, $(basename $(BONUS_SRC)))

all:	${NAME}

-include ${DEPS}
${NAME}: ${OBJS} $(INCLUDE)
	@${CC} ${SRCS} -o ${NAME}
	@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"

-include ${DEPS2}
bonus: ${BONUS_OBJS}
				@touch $@
				@${CC} ${BONUS_SRC} -o ${NAME_BONUS}
				@echo "\n$(GREEN)Created ${NAME_BONUS} ✓$(DEF_COLOR)\n"

clean:
			@${RM} ${OBJS} ${BONUS_OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@echo "\n $(RED)Objects cleaned! $(DEF_COLOR)\n"

fclean: 
			@${RM} ${OBJS} ${BONUS_OBJS}
			@${RM} ${DEPS} ${DEPS2}
			@${RM} bonus
			@${RM} ${NAME} ${NAME_BONUS}
			@echo "\n $(RED)Objects and ejecutables cleaned! $(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re