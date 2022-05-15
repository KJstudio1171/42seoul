/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:29:52 by junekim           #+#    #+#             */
/*   Updated: 2022/05/04 17:45:33 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_conversion(char c, va_list ap, int *num)
{
	if (c == 'c')
		ft_putchar(va_arg(ap, int), num);
	else if (c == 's')
		ft_putstr(va_arg(ap, char *), num);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		*num += 2;
		puthexa(va_arg(ap, unsigned long), 0, num);
	}
	else if (c == 'd')
		ft_putnbr(va_arg(ap, int), num);
	else if (c == 'i')
		ft_putnbr(va_arg(ap, int), num);
	else if (c == 'u')
		ft_unsinged_putnbr(va_arg(ap, unsigned int), num);
	else if (c == 'x')
		puthexa(va_arg(ap, unsigned int), 0, num);
	else if (c == 'X')
		puthexa(va_arg(ap, unsigned int), 1, num);
	else if (c == '%')
		counter_write(1, "%", 1, num);
}

static int	format_checker(char c)
{
	char	*format;

	format = "cspdiuxX%";
	while (*format)
	{
		if (c == *format)
			return (1);
		format++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num;

	num = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			counter_write(1, format, 1, &num);
		else
		{
			if (format_checker(*(format + 1)))
			{
				parse_conversion(*(format + 1), ap, &num);
				format += 2;
				continue ;
			}
			else
				return (-1);
		}
		format ++;
	}
	va_end(ap);
	return (num);
}
