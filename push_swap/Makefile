# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD:minitalk/Makefile
#    Created: 2021/12/31 13:00:54 by junekim           #+#    #+#              #
#    Updated: 2022/06/21 19:15:55 by junekim          ###   ########seoul.kr   #
=======
#    Created: 2022/05/04 15:57:01 by junekim           #+#    #+#              #
#    Updated: 2022/05/18 19:45:10 by junekim          ###   ########.fr        #
>>>>>>> f7193f6458ec0d529c9bd769f584e4c3065eab5d:printf/Makefile
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
<<<<<<< HEAD:minitalk/Makefile
	make clean -C ./libft
	$(RM) server.o client.o
=======
	$(RM) $(OBJS)
>>>>>>> f7193f6458ec0d529c9bd769f584e4c3065eab5d:printf/Makefile

fclean : clean
	make fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all bonus clean fclean re .c.o