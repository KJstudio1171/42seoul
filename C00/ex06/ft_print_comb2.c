/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:44:32 by junekim           #+#    #+#             */
/*   Updated: 2021/09/16 16:12:09 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	next_com(int *a, int *b)
{
	if ((*a)++ == 9)
	{
		(*b)++;
		*a = 0;
	}
}

void	ft_write(int *i, int *j, int *k, int *l)
{
	char	*number;

	number = "0123456789, ";
	write(1, &number[*i], 1);
	write(1, &number[*j], 1);
	write(1, &number[11], 1);
	write(1, &number[*k], 1);
	write(1, &number[*l], 1);
	write(1, &number[10], 2);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (i < 10)
	{
		l = (j + 1) % 10;
		k = i + (j + 1) / 10;
		while (k < 10)
		{
			if (! (i == 9 && j == 8))
				ft_write(&i, &j, &k, &l);
			else
			{
				write(1, "98 99", 5);
				return ;
			}
			next_com(&l, &k);
		}
		next_com(&j, &i);
	}
}
