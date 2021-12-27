#!bin/bash

gcc -c -Wall -Wextra -Werror *.c
ar -rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o