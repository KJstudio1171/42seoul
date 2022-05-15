# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:57:01 by junekim           #+#    #+#              #
#    Updated: 2022/05/04 17:02:40 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

OBJS = $(SRCS:%.c=%.o)

NAME = libftprintf.a

OBJECTS = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re .c.o