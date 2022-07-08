/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:08:21 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 10:09:26 by junekim          ###   ########seoul.kr  */
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

void	reverse_rotate(t_info *info, int op1, int op2)
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
