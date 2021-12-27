/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:11:44 by junekim           #+#    #+#             */
/*   Updated: 2021/09/14 17:42:48 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;
	char	*number;

	number = "0123456789, ";
	i = 0;
	while (i < 8)
	{
		j = i + 1;
		while (j < 9)
		{
			k = j + 1;
			while (k < 10)
			{
				write(1, &number[i], 1);
				write(1, &number[j], 1);
				write(1, &number[k++], 1);
				if (!(i == 7 && j == 8 && k == 10))
					write(1, &number[10], 2);
			}
			j++;
		}
		i++;
	}
}
