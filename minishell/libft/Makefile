# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiturria <aiturria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 11:32:27 by aiturria          #+#    #+#              #
#    Updated: 2024/07/16 10:42:10 by aiturria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc
LIBC	= ar rcs
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a
SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf.c ft_numbers.c ft_hexadecimals.c get_next_line.c \
		get_next_line_utils.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS	= $(BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS_BONUS) 
	@$(LIBC)	$(NAME)	$(OBJS)	$(OBJS_BONUS)

bonus:	$(OBJS_BONUS)
	@$(LIBC)	$(NAME) $(OBJS_BONUS)

%.o:	%.c
	@$(CC)	$(CFLAGS) -c $< -I./ -o $@

clean:
	@-rm -rf $(OBJS)	$(OBJS_BONUS)

fclean:clean
	@-rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
