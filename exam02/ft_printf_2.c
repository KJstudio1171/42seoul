/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:32:45 by junekim           #+#    #+#             */
/*   Updated: 2022/08/25 02:48:46 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_putstr(char *string)
{
	int count = 0;
	if (!string)
		return (write(1, "(null)", 6));
	while(string[count])
	{
		count += write(1, &string[count], 1);
	}
	return (count);
}

int	ft_putnbr(long long n, int base)
{
	int count = 0;
	char *nb = "0123456789abcdef";
	
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n / base > 0)
		count += ft_putnbr(n / base, base);
	count += write(1, &nb[n % base], 1);
	return (count);
}

int ft_printf(char * str, ...)
{
	va_list ap;
	int count = 0;
	int i = 0;

	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
				count += ft_putnbr(va_arg(ap, int), 10);
			else if (str[i] == 'x')
				count += ft_putnbr(va_arg(ap, unsigned int), 16);
			else if (str[i] == 's')
				count += ft_putstr(va_arg(ap, char*));
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
