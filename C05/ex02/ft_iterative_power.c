/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:24:48 by junekim           #+#    #+#             */
/*   Updated: 2021/09/22 20:28:23 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	value;

	i = 0;
	value = 1;
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i++ < power)
	{
		value *= nb;
	}
	return (value);
}
