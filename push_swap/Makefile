# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 13:00:54 by junekim           #+#    #+#              #
#    Updated: 2022/07/08 10:11:19 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = op_push.c op_reverse_rotate.c op_rotate.c op_swap.c sort_low_number.c\
		min_max_swap.c quicksort_stack.c print.c quicksort_stack_utils.c error.c\
		stack_utils.c is_inputable.c get_next_line.c arr_utils.c

OBJS = $(SRCS:%.c=%.o)

LIBFT = ./libft/libft.a

PUSH_SWAP = push_swap
CHECKER = checker

all : $(PUSH_SWAP) $(CHECKER)

$(LIBFT) :
	make -C ./libft

$(PUSH_SWAP) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) push_swap.c ./libft/libft.a -o $(PUSH_SWAP)

$(CHECKER) : $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) checker.c ./libft/libft.a -o $(CHECKER)

clean :
	make clean -C ./libft
	$(RM) $(OBJS) push_swap.o checker.o

fclean : clean
	make fclean -C ./libft
	$(RM) $(PUSH_SWAP) $(CHECKER)

re : fclean all

.PHONY : all bonus clean fclean re