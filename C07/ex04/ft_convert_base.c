/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:38:11 by junekim           #+#    #+#             */
/*   Updated: 2021/09/28 12:06:50 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base);
int		is_space(char ch);

int	is_number(char *ch, char *base, int base_len, int *number)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < base_len)
	{
		if (*ch == base[i])
		{
			result = 1;
			*number = i;
			break ;
		}
		i++;
	}
	return (result);
}

int	count_int(int *i, char *str, char *base, int base_len)
{
	int	count;
	int	number;

	count = 0;
	number = 0;
	while (is_space(str[*i]))
		(*i)++;
	while (str[*i])
	{
		if (is_number(&str[*i], base, base_len, &number))
			break ;
		if (str[*i] != '-' && str[*i] != '+')
			return (-1);
		if (str[*i] == '-')
		{
			count++;
		}
		(*i)++;
	}
	return (count);
}

int	is_printable(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*base == '\0')
		return (0);
	else if (base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		while (j < i)
		{
			if (base[j++] == base[i])
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base, int count, int *i)
{
	long long	atoi;
	int			base_len;
	int			number;

	atoi = 0;
	base_len = 0;
	number = 0;
	while (base[base_len])
		base_len++;
	while (is_number(&str[(*i)++], base, base_len, &number))
	{
		atoi *= base_len;
		atoi += number;
	}
	if (count % 2 == 1)
		atoi *= -1;
	return ((int)atoi);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	n;
	int	i;
	int	count;
	int	base_from_len;

	base_from_len = 0;
	while (base_from[base_from_len])
		base_from_len++;
	i = 0;
	count = count_int(&i, nbr, base_from, base_from_len);
	if (!is_printable(base_from))
		return (NULL);
	if (!is_printable(base_to))
		return (NULL);
	if (count == -1)
		return (ft_putnbr_base(0, base_to));
	n = ft_atoi_base(nbr, base_from, count, &i);
	return (ft_putnbr_base(n, base_to));
}
