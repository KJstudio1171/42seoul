/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:56:04 by junekim           #+#    #+#             */
/*   Updated: 2021/09/22 22:02:29 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (n < 46340 && n * n > nb)
	{
		if (nb % n++ == 0)
			return (0);
	}
	return (1);
}