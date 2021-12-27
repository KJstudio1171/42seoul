CFLAGS=-Wall -Wextra -Werror
CC=gcc
TARGET=libft.a
SRCS=srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS=${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@ -Iincludes

${TARGET} : ${OBJS}
	ar rc $@ $^


all : ${TARGET}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${TARGET}

re : fclean all

.PHONY : all clean fclean re .c.o