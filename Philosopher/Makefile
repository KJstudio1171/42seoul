# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 15:04:40 by junekim           #+#    #+#              #
#    Updated: 2022/09/04 21:40:07 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_DIR = srcs/
SRCS_FILES = philo.c philo_utils.c philo_stop.c philo_init.c philo_atoi.c philo_act.c is_philo.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS_DIR = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

NAME = philo/philo

all : $(NAME)

$(NAME) : $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

clean :
	$(RM) $(OBJS_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re