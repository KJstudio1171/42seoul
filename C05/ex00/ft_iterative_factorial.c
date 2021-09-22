/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:01:07 by junekim           #+#    #+#             */
/*   Updated: 2021/09/22 20:15:59 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_interative_factorial(int nb)
{
	int	value;

	value = 1;
	if (nb < 1)
		return (0);
	while (nb > 0)
	{
		value *= nb--;
	}
	return (value);
}
