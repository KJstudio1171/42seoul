/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:47:53 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 07:29:14 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	min_data(t_stack *head, int len)
{
	int	min;

	min = head->data;
	head = head->prev;
	while (head && --len)
	{
		if (head->data < min)
			min = head->data;
		head = head->prev;
	}
	return (min);
}

int	max_data(t_stack *head, int len)
{
	int	max;

	max = head->data;
	head = head->prev;
	while (head && --len)
	{
		if (head->data > max)
			max = head->data;
		head = head->prev;
	}
	return (max);
}
