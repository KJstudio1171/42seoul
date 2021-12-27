/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:59:04 by junekim           #+#    #+#             */
/*   Updated: 2021/09/30 15:13:22 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	mode(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len != 1)
	{
		write(1, "0", 1);
		return (-1);
	}
	if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '*')
		return (2);
	else if (*str == '/')
		return (3);
	else if (*str == '%')
		return (4);
	else
	{
		write(1, "0", 1);
		return (-1);
	}
}

void	stop(int function_number)
{
	if (function_number == 3)
	{
		write(1, "Stop : division by zero\n", 24);
	}
	if (function_number == 4)
	{
		write(1, "Stop : modulo by zero\n", 22);
	}
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	function_number;
	int	(*f[5])(int, int);

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	function_number = mode(argv[2]);
	if (b == 0 && (function_number == 3 || function_number == 4))
	{
		stop(function_number);
		return (0);
	}
	if (function_number == -1)
		return (0);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	ft_putnbr(f[function_number](a, b));
}
