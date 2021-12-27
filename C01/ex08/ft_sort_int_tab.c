/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:59:00 by junekim           #+#    #+#             */
/*   Updated: 2021/09/16 16:26:49 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		min = tab[i];
		j = i + 1;
		while (j < size)
		{
			if (min > tab[j])
			{
				min = tab[j];
				tab[j] = tab[i];
				tab[i] = min;
			}
			j++;
		}
		i++;
	}
}
