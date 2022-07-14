# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <june1171@naver.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 13:00:54 by junekim           #+#    #+#              #
#    Updated: 2022/07/05 23:14:28 by junekim          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SERVER = server
CLIENT = client

all : 
	make -C ./libft
	$(CC) $(CFLAGS) server.c ./libft/libft.a -o $(SERVER)
	$(CC) $(CFLAGS) client.c ./libft/libft.a -o $(CLIENT)

clean :
	make clean -C ./libft
	$(RM) server.o client.o

fclean : clean
	make fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all bonus clean fclean re