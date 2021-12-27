/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:25:03 by junekim           #+#    #+#             */
/*   Updated: 2021/09/16 16:12:24 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int *nb)
{
	int		a[10];
	char	b[10];
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*nb / 10 != 0)
	{
		a[count] = *nb % 10;
		count++;
		*nb /= 10;
	}
	a[count] = *nb;
	while (count >= 0)
	{
		b[i++] = a[count--] + 48;
	}
	write(1, b, i);
}

void	ft_putnbr(int	nb)
{
	int		sign;

	sign = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		sign = 1;
		nb = nb * -1;
		write(1, "-", 1);
	}
	ft_write(&nb);
}
