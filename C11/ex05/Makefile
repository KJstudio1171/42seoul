CFLAGS=-Wall -Wextra -Werror
CC=gcc
TARGET=do-op
SRCS=ft.c ft_putnbr.c ft_atoi.c main.c
OBJS=${SRCS:.c=.o}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@

${TARGET} : ${OBJS}
	gcc -o $@ $^


all : ${TARGET}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${TARGET}

re : fclean all

.PHONY : all clean fclean re .c.o