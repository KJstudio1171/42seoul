/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:27:27 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 12:36:15 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*range;
	int			i;
	long long	size;

	if (min >= max)
		return (NULL);
	i = 0;
	size = (long long)max - (long long)min;
	range = (int *)malloc(sizeof(int) * size);
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
