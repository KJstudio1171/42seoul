/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:18:03 by junekim           #+#    #+#             */
/*   Updated: 2022/08/25 02:48:51 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n, int base)
{
	char *nbr = "0123456789abcdef";
	int count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n *= -1;
	}
	if (n / base > 0)
		count += ft_putnbr(n / base, base);
	write(1, &nbr[n % base], 1);
	count += 1;
	return (count);
}

int ft_putstr(char *str)
{
	int count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while(*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char * str,...)
{
	va_list ap;
	int count = 0;
	int i = 0;

	va_start(ap, str);
	while(str[i])
	{
		if(str[i] == '%')
		{
			i++;
			if(str[i] == 's')
			{
				count += ft_putstr(va_arg(ap, char *));
			}
			else if (str[i] == 'd')
			{
				count += ft_putnbr(va_arg(ap, int), 10);
			}
			else if (str[i] == 'x')
			{
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			}
		}
		else
		{
			write(1, &str[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(ap);
	return count;
}