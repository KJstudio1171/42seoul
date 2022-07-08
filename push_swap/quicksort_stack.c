/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:06:46 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 09:21:56 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_info *info)
{
	int		i;
	int		count;
	t_stack	*tmp;

	i = 0;
	count = 0;
	tmp = info->a_head;
	while (i < info->len && tmp)
	{
		if (info->sorted_arr[i] == tmp->data)
		{
			tmp = tmp->prev;
			i++;
			count++;
			continue ;
		}
		break ;
	}
	if (count == info->len && !info->b_num)
		return (1);
	else
		return (0);
}

void	find_pivot(t_info *info, int *pivot, int min, int num)
{
	int	i;

	i = 0;
	while (i < info ->len)
	{
		if (min == info->sorted_arr[i])
			break ;
		i++;
	}
	pivot[0] = info->sorted_arr[i + num - 1 - (num / 3)];
	pivot[1] = info->sorted_arr[i + num / 3];
}

static void	reverse_rotate_sub(t_info *info, int op1, int op2)
{
	int	i;

	i = 0;
	if (op1 < op2)
	{
		while (i < op1)
		{
			rrr(info);
			i++;
		}
		while (i++ < op2)
			rrb(info);
	}
	else
	{
		while (i < op2)
		{
			rrr(info);
			i++;
		}
		while (i++ < op1)
			rra(info);
	}
}

static void	reverse_rotate(t_info *info, int op1, int op2)
{
	int	i;

	if (!(info->a_tail && info->b_tail
			&& info->a_tail->next && info->b_tail->next))
	{
		i = 0;
		while (i++ < op1)
			rra(info);
		i = 0;
		while (i++ < op2)
			rrb(info);
	}
	else
		reverse_rotate_sub(info, op1, op2);
}

void	quicksort_stack_a(t_info *info, int num)
{
	int	pivot[2];
	int	op_num[3];
	int	i;

	if (!num)
		return ;
	if (is_sorted(info))
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
	while (num)
	{
		if (info->a_head->data >= pivot[0])
		{
			ra(info);
			op_num[0]++;
			num--;
		}
		else if (info->a_head->data >= pivot[1])
		{
			pb(info);
			op_num[1]++;
			if (info->a_head && info->b_head && info->a_head->prev
				&& info->b_head->prev && num >= 2 && info->a_head->data >= pivot[0])
			{
				rr(info);
				op_num[0]++;
				op_num[2]++;
				num -= 2;
			}
			else
			{
				rb(info);
				op_num[2]++;
				num--;
			}
		}
		else
		{
			pb(info);
			op_num[1]++;
			num--;
		}
	}
	reverse_rotate(info, op_num[0], op_num[2]);
	quicksort_stack_a(info, op_num[0]);
	quicksort_stack_b(info, op_num[2]);
	quicksort_stack_b(info, op_num[1] - op_num[2]);
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
	while (num)
	{
		if (info->b_head->data >= pivot[0])
		{
			pa(info);
			op_num[0]++;
			num--;
		}
		else if (info->b_head->data >= pivot[1])
		{
			pa(info);
			op_num[0]++;
			if (info->a_head && info->b_head
			&& info->a_head->prev && info->b_head->prev && num >= 2 && info->b_head->data < pivot[1])
			{
				rr(info);
				op_num[1]++;
				op_num[2]++;
				num -= 2;
			}
			else
			{
				ra(info);
				op_num[1]++;
				num--;
			}
		}
		else
		{
			rb(info);
			op_num[2]++;
			num--;
		}
	}
	quicksort_stack_a(info, op_num[0] - op_num[1]);
	reverse_rotate(info, op_num[1], op_num[2]);
	quicksort_stack_a(info, op_num[1]);
	quicksort_stack_b(info, op_num[2]);
	return ;
}
