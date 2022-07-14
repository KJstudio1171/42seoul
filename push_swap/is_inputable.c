/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_inputable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:14:50 by junekim           #+#    #+#             */
/*   Updated: 2022/07/09 09:12:50 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-' && argv[i][j + 1] != '\0')
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_not_int_sub(char **argv, int i)
{
	size_t	len;

	if (argv[i][0] == '-')
		len = 1;
	else
		len = 0;
	while (argv[i][len] == '0')
		len++;
	len = ft_strlen(argv[i]) - len;
	if (len > 10)
		return (1);
	else if (len == 10)
	{
		if (argv[i][1] > '3')
			return (1);
		else if (argv[i][0] == '-' && ft_atoi(argv[i]) > 0)
			return (1);
		else if (argv[i][0] != '-' && ft_atoi(argv[i]) < 0)
			return (1);
	}
	return (0);
}

static int	is_not_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_not_int_sub(argv, i))
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_inputable(int argc, char **argv)
{
	if (is_not_digit(argc, argv) || is_not_int(argc, argv)
		|| is_duplicate(argc, argv))
		return (1);
	return (0);
}
