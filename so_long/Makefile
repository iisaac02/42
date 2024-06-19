NAME		=	so_long
CC			=	clang
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

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

SRC			=	src/die.c \
				src/draw.c \
				src/event.c \
				src/game_destroy.c \
				src/game_init.c \
				src/map_height.c \
				src/map_init.c \
				src/map_isvalid.c \
				src/map_parsing.c \
				src/map_read.c \
				src/map_width.c \
				src/utils.c \
				src/move_player.c \
				src/root_destroy.c \
				src/root_init.c \
				src/so_long.c \
				src/update.c

all:		$(MLX) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)
			@echo "\n$(GREEN) SO LONG created! ✔ $(DEF_COLOR)\n"


$(MLX):
			@make -s -C mlx
			@echo "\n$(YELLOW) MLX42 ready! ✔ $(DEF_COLOR)\n"

$(LFT):		

			@make -s -C libft
			@echo "\n$(YELLOW) Libft ready! ✔ $(DEF_COLOR)\n"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "\n$(RED)Program removed. $(DEF_COLOR)\n"

fclean:
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@rm -rf $(OBJ) obj
			@echo "\n $(RED)SO LONG removed, bye!. $(DEF_COLOR)\n"

re:			fclean all

.PHONY:		all clean fclean re
