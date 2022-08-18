# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 15:04:40 by junekim           #+#    #+#              #
#    Updated: 2022/08/18 13:52:23 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx
RM = rm -rf

SRCS_DIR = srcs/
SRCS_FILES = so_long.c character.c map.c error.c get_next_line.c init.c close.c image.c map_parser.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

SRCS_DIR_BONUS = srcs_bonus/
SRCS_FILES_BONUS = so_long.c character.c map.c error.c get_next_line.c init.c close.c image.c \
frame.c start.c init_image.c init_image_sub.c animation.c animate_image_64.c missile.c print_move.c \
init_animation.c map_parser.c
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS), $(SRCS_FILES_BONUS))

OBJS_DIR = objs/
OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

OBJS_DIR_BONUS = objs_bonus/
OBJS_BONUS = $(SRCS_BONUS:$(SRCS_DIR_BONUS)%.c=$(OBJS_DIR_BONUS)%.o)

LIBFT = libft/libft.a

NAME = so_long
NAME_BONUS = so_long_bonus

all : $(NAME)
bonus : $(NAME_BONUS)

$(LIBFT) :
	make -C ./libft

$(NAME) : $(OBJS_DIR) $(OBJS)
	make -C ./libft
	arch -x86_64 $(CC) -g $(OBJS) $(LIBFT) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BONUS) : $(OBJS_DIR_BONUS) $(OBJS_BONUS)
	make -C ./libft
	arch -x86_64 $(CC) -g $(OBJS_BONUS) $(LIBFT) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	arch -x86_64 $(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_BONUS)%.o : $(SRCS_DIR_BONUS)%.c
	arch -x86_64 $(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_DIR_BONUS) :
	mkdir $(OBJS_DIR_BONUS)

clean :
	make clean -C ./libft
	$(RM) $(OBJS_DIR) $(OBJS_DIR_BONUS)

fclean : clean
	make fclean -C ./libft
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all bonus clean fclean re