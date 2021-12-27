/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:36:46 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 16:40:55 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

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

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	long long	atoi;
	int			count;
	int			base_len;
	int			number;

	i = 0;
	atoi = 0;
	base_len = 0;
	number = 0;
	if (!is_printable(base))
		return (0);
	while (base[base_len])
		base_len++;
	count = count_int(&i, str, base, base_len);
	if (count == -1 || str[i] == '\0')
		return (0);
	while (is_number(&str[i++], base, base_len, &number))
	{
		atoi *= base_len;
		atoi += number;
	}
	if (count % 2 == 1)
		atoi *= -1;
	return ((int)atoi);
}
