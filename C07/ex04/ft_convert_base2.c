/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:38:10 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 16:49:06 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	find_digit(long long n, int len)
{
	int			digit;
	long long	num;

	num = n;
	digit = 0;
	if (num < 0)
	{
		digit++;
		num *= -1;
	}
	while (num / len > 0)
	{
		digit++;
		num /= len;
	}
	return (digit + 1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			len;
	int			digit;
	long long	num;
	char		*printnum;

	len = 0;
	digit = 0;
	num = (long long) nbr;
	while (base[len])
		len++;
	digit = find_digit(num, len);
	printnum = (char *)malloc(sizeof(char) * (digit + 1));
	if (num < 0)
	{
		printnum[0] = '-';
		num *= -1;
	}
	printnum[digit] = '\0';
	while (num / len > 0)
	{
		printnum[--digit] = base[num % len];
		num /= len;
	}
	printnum[--digit] = base[num % len];
	return (printnum);
}
