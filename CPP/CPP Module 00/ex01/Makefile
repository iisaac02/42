NAME = phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS_FOLDER = .o
VPATH = src/
RM = rm -rf

SRCS =	contact.cpp \
		phonebook.cpp \
		main.cpp

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

re: fclean all

all: ${NAME}

.PHONY: all clean fclean re
