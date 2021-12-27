/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:35:53 by junekim           #+#    #+#             */
/*   Updated: 2021/09/30 17:33:21 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	is_sort;
	int	i;

	is_sort = 0;
	i = -1;
	while (++i < length - 1)
	{
		if (is_sort == 0)
		{
			is_sort = (*f)(tab[i], tab[i + 1]);
			continue ;
		}
		if ((*f)(tab[i], tab[i + 1]) == 0)
			continue ;
		if ((*f)(tab[i], tab[i + 1]) > 0 && is_sort > 0)
			continue ;
		if ((*f)(tab[i], tab[i + 1]) < 0 && is_sort < 0)
			continue ;
		return (0);
	}
	return (1);
}
