NAME = account

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = base
RM = rm -rf

SRCS =	Account.cpp\
		tests.cpp
OBJS = ${SRCS:%.cpp=${OBJS_FOLDER}/%.o}

${NAME}: ${OBJS}
	@${CXX} ${OBJS} -o ${NAME}

${OBJS_FOLDER}:
	@mkdir -p ${OBJS_FOLDER}

${OBJS_FOLDER}/%.o: %.cpp | ${OBJS_FOLDER}
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	@${RM} ${OBJS_FOLDER}

fclean: clean
	@${RM} ${NAME}

all: ${NAME}

re: fclean all

.PHONY: clean fclean all re
