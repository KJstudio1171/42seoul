/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:53:48 by junekim           #+#    #+#             */
/*   Updated: 2022/05/04 17:44:52 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	counter_write(int fd, const void *buf, size_t count, int *num)
{
	*num += count;
	write(fd, buf, count);
}

void	ft_putnbr(int n, int *num)
{
	char	*nbr;

	nbr = "0123456789";
	if (n == -2147483648)
	{
		counter_write(1, "-2147483648", 11, num);
		return ;
	}
	if (n < 0)
	{
		counter_write(1, "-", 1, num);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10, num);
	counter_write(1, &nbr[n % 10], 1, num);
}

void	ft_unsinged_putnbr(unsigned int n, int *num)
{
	char	*nbr;

	nbr = "0123456789";
	if (n >= 10)
		ft_unsinged_putnbr(n / 10, num);
	counter_write(1, &nbr[n % 10], 1, num);
}

int	puthexa(unsigned long n, int mode, int *num)
{
	char	*small;
	char	*big;

	small = "0123456789abcdef";
	big = "0123456789ABCDEF";
	if (n >= 16)
		puthexa((unsigned long)(n / 16), mode, num);
	if (mode)
		counter_write(1, &big[n % 16], 1, num);
	else
		counter_write(1, &small[n % 16], 1, num);
	return (1);
}
