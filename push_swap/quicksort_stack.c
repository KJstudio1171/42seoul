/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:06:46 by junekim           #+#    #+#             */
/*   Updated: 2022/07/09 01:19:29 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_execution(t_info *info, int *op_num, int mode)
{
	if (mode == 1)
		pa(info);
	else if (mode == 2)
		pb(info);
	else if (mode == 3)
		ra(info);
	else if (mode == 4)
		rb(info);
	else if (mode == 5)
		rr(info);
	(*op_num)++;
}

static void	stack_a_sub(t_info *info, int num, int *op_num, int *pivot)
{
	while (num)
	{
		if (info->a_head->data >= pivot[0])
			op_execution(info, &op_num[0], 3);
		else if (info->a_head->data >= pivot[1])
		{
			op_execution(info, &op_num[1], 2);
			if (info->a_head && info->b_head && info->a_head->prev
				&& info->b_head->prev && num >= 2
				&& info->a_head->data >= pivot[0])
			{
				op_execution(info, &op_num[0], 5);
				op_num[2]++;
				num --;
			}
			else
				op_execution(info, &op_num[2], 4);
		}
		else
			op_execution(info, &op_num[1], 2);
		num--;
	}
}

void	quicksort_stack_a(t_info *info, int num)
{
	int	pivot[2];
	int	op_num[3];
	int	i;

	if (!num || is_sorted(info))
		return ;
	if (info->a_num <= 5 && info->a_num == num)
	{
		sort_low_number(info, info->a_num);
		return ;
	}
	if (num <= 3)
	{
		sort_low_number(info, num);
		return ;
	}
	find_pivot(info, pivot, min_data(info->a_head, num), num);
	i = 0;
	while (i < 3)
		op_num[i++] = 0;
	stack_a_sub(info, num, op_num, pivot);
	reverse_rotate(info, op_num[0], op_num[2]);
	quicksort_stack_a(info, op_num[0]);
	quicksort_stack_b(info, op_num[2]);
	quicksort_stack_b(info, op_num[1] - op_num[2]);
}

static void	stack_b_sub(t_info *info, int num, int *op_num, int *pivot)
{
	while (num)
	{
		if (info->b_head->data >= pivot[0])
			op_execution(info, &op_num[0], 1);
		else if (info->b_head->data >= pivot[1])
		{
			op_execution(info, &op_num[0], 1);
			if (info->a_head && info->b_head
				&& info->a_head->prev && info->b_head->prev
				&& num >= 2 && info->b_head->data < pivot[1])
			{
				op_execution(info, &op_num[1], 5);
				op_num[2]++;
				num--;
			}
			else
				op_execution(info, &op_num[1], 3);
		}
		else
		{
			rb(info);
			op_num[2]++;
		}
		num--;
	}
}

void	quicksort_stack_b(t_info *info, int num)
{
	int	pivot[2];
	int	op_num[3];
	int	i;

	if (!num)
		return ;
	find_pivot(info, pivot, min_data(info->b_head, num), num);
	i = 0;
	while (i < 3)
		op_num[i++] = 0;
	stack_b_sub(info, num, op_num, pivot);
	quicksort_stack_a(info, op_num[0] - op_num[1]);
	reverse_rotate(info, op_num[1], op_num[2]);
	quicksort_stack_a(info, op_num[1]);
	quicksort_stack_b(info, op_num[2]);
	return ;
}
