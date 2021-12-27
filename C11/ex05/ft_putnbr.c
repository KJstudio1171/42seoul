/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:26:09 by junekim           #+#    #+#             */
/*   Updated: 2021/09/30 14:44:20 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	positive_check(int *n, int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	*n = nb;
	return (nb);
}

void	ft_putnbr(int nb)
{
	int		i;
	int		size;
	int		n;
	char	num[10];

	size = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	nb = positive_check(&n, nb);
	while (n / 10 > 0)
	{
		n /= 10;
		size++;
	}
	i = size;
	while (nb / 10 > 0)
	{
		num[i--] = nb % 10 + '0';
		nb /= 10;
	}
	num[i] = nb % 10 + '0';
	write(1, num, size + 1);
}
