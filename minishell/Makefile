# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 14:19:00 by aiturria          #+#    #+#              #
#    Updated: 2024/07/19 09:44:06 by ide-la-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	clang
CFLAGS	= -Wall -Wextra -Werror -g
LDFLAGS = -lreadline
PARSER = ./parser/
EXEC = ./exec/

NAME	= minishell

SRCS	= $(EXEC)ms_minishell.c $(PARSER)ms_parser01.c $(PARSER)ms_parser02.c \
		$(PARSER)ms_tokens01.c $(PARSER)ms_utils.c  $(PARSER)ms_signals.c \
		$(PARSER)ms_signals2.c $(PARSER)ms_environment.c $(PARSER)ms_validation.c\
		$(EXEC)ms_heredoc.c  $(EXEC)ms_execution1.c $(EXEC)ms_redirections.c \
		$(EXEC)ms_builtin1.c $(EXEC)ms_builtin2.c $(EXEC)ms_builtin3.c \
		$(EXEC)ms_builtin4.c $(EXEC)ms_path.c

DEF_COLOR =		\033[0;39m
RED = 			\033[0;91m
GREEN = 		\033[0;92m

MYLIB	= ./libft/libft.a
LIBFT	= ./libft
		
OBJS	= $(SRCS:.c=.o)

all:	$(LIBFT) $(NAME)

$(LIBFT)/libft.a:
	@make -s -C $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	@mkdir -p ./temp
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)  $(MYLIB) $(LDFLAGS)
	@echo "\n$(GREEN)MYSHELL CREATED$(DEF_COLOR)\n"

%.o:	%.c
	@$(CC)	$(CFLAGS) -c $< -I./ -o $@

clean:
	@-rm -f $(OBJS)
	@make -s -C $(LIBFT) clean

fclean:clean
	@-rm -f $(NAME)
	@make -s -C $(LIBFT) fclean
	@-rm -rf ./temp
	@echo "\n$(RED)MYSHELL REMOVED$(DEF_COLOR)\n"

re: fclean all

.PHONY:	all clean fclean re
