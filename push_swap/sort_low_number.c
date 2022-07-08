/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:55:51 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 10:04:52 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_number_three_sub(t_info *info, int mode)
{
	if (mode == 0)
		if (info->a_head->data > info->a_head->prev->data)
			sa(info);
	if (mode == 1)
	{
		pb(info);
		sort_number_three_sub(info, 0);
		pa(info);
	}
	else if (mode == 2)
	{
		sa(info);
		pb(info);
		sort_number_three_sub(info, 0);
		pa(info);
	}
	else if (mode == 3)
	{
		pb(info);
		sort_number_three_sub(info, 0);
		ra(info);
		pa(info);
		sort_number_three_sub(info, 0);
		rra(info);
	}
}

static void	sort_number_three(t_info *info)
{
	int		value[3];
	int		arr[3];
	t_stack	*tmp;

	value[2] = 0;
	tmp = info->a_head;
	value[0] = min_data(tmp, 3);
	value[1] = max_data(tmp, 3);
	while (value[2] < 3)
	{
		arr[value[2]++] = tmp->data;
		tmp = tmp->prev;
	}
	if (info->a_num == 3)
	{
		if (arr[1] == value[1])
			rra(info);
		else if (arr[0] == value[1])
			ra(info);
	}
	else
		while (value[2])
			if (arr[--value[2]] == value[0])
				sort_number_three_sub(info, value[2] + 1);
	sort_number_three_sub(info, 0);
}

static void	sort_number_four(t_info *info)
{
	int		i;
	int		min;
	t_stack	*tmp;

	i = 0;
	tmp = info->a_head;
	min = min_data(tmp, 4);
	while (i < 4)
	{
		if (tmp->data == min)
			break ;
		tmp = tmp->prev;
		i++;
	}
	if (i == 3)
		rra(info);
	else
		while (i-- > 0)
			ra(info);
	pb(info);
	sort_number_three(info);
	pa(info);
}

static void	sort_number_five(t_info *info)
{
	int		i;
	int		min;
	t_stack	*tmp;

	i = 0;
	tmp = info->a_head;
	min = min_data(tmp, 5);
	while (i < 5)
	{
		if (tmp->data == min)
			break ;
		tmp = tmp->prev;
		i++;
	}
	if (i == 3 || i == 4)
		while (i++ < 5)
			rra(info);
	else
		while (i-- > 0)
			ra(info);
	pb(info);
	sort_number_four(info);
	pa(info);
}

void	sort_low_number(t_info *info, int number)
{
	int	max;

	if (number == 1)
		return ;
	else if (number == 2)
	{
		max = max_data(info->a_head, 2);
		if (info->a_head->data == max)
			sa(info);
	}
	else if (number == 3)
		sort_number_three(info);
	else if (number == 4)
		sort_number_four(info);
	else if (number == 5)
		sort_number_five(info);
}
