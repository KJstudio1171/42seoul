/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:58:57 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 15:47:36 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(int *len, char *base)
{
	int	i;

	i = 0;
	if (*base == '\0')
		return (0);
	else if (base[1] == '\0')
		return (0);
	while (base[*len])
	{
		if (base[*len] == '+' || base[*len] == '-')
			return (0);
		while (i < *len)
		{
			if (base[i++] == base[*len])
				return (0);
		}
		i = 0;
		(*len)++;
	}
	return (1);
}

int	find_digit(long long n, int len)
{
	int			digit;
	long long	num;

	num = n;
	digit = 0;
	while (num / len > 0)
	{
		digit++;
		num /= len;
	}
	return (digit + 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			len;
	int			digit;
	long long	num;
	char		printnum[32];

	len = 0;
	digit = 0;
	num = (long long) nbr;
	if (!is_printable(&len, base))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	digit = find_digit(num, len);
	i = digit;
	while (num / len > 0)
	{
		printnum[--digit] = base[num % len];
		num /= len;
	}
	printnum[--digit] = base[num % len];
	write(1, printnum, i);
}
