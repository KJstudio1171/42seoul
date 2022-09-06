/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:20:02 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 01:09:55 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (4);
	else
		return (0);
}

int	philo_atoi(const char *nptr)
{
	long long	digit;
	int			i;

	digit = 0;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		digit *= 10;
		digit += (nptr[(i)++] - '0');
		if (digit > 2147483647)
			return (-1);
	}
	if (nptr[i])
		return (-1);
	return ((int)digit);
}
