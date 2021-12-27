/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 13:34:00 by junekim           #+#    #+#             */
/*   Updated: 2021/09/30 16:11:04 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			result++;
		i++;
	}
	return (result);
}
