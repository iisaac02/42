NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re