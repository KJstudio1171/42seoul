/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:16:39 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:11:35 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	itoa_malloc(int n, int *i, char *str)
{
	int		size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	*i += size;
	str = (char *)malloc(sizeof(char) * (*i + 1));
	if (str)
		str[(*i)--] = '\0';
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		i;

	neg = 0;
	str = NULL;
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	i = neg ;
	itoa_malloc(n, &i, str);
	if (!str)
		return (NULL);
	while (n)
	{
		str[i--] = (n % 10) - '0';
		n /= 10;
	}
	if (neg == 1)
		str[i] = '-';
	return (str);
}
