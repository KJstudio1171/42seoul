/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:40:46 by junekim           #+#    #+#             */
/*   Updated: 2021/09/23 16:45:38 by junekim          ###   ########.fr       */
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
	while (n < 46341 && n * n <= nb)
		if (nb % n++ == 0)
			return (0);
	return (1);
}