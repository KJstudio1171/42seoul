/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:37:51 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 01:16:09 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_stack	*tmp;

	if (!(info->b_head))
		return ;
	tmp = info->b_head;
	if (tmp->prev)
		tmp ->prev->next = NULL;
	else
		info->b_tail = NULL;
	info->b_head = tmp->prev;
	if (!(info->a_head))
	{
		tmp->prev = NULL;
		info->a_tail = tmp;
	}
	else
	{
		info->a_head->next = tmp;
		tmp -> prev = info->a_head;
	}
	info->a_head = tmp;
	info->a_num += 1;
	info -> b_num -= 1;
	print_op(info, "pa\n");
}

void	pb(t_info *info)
{
	t_stack	*tmp;

	if (!(info->a_head))
		return ;
	tmp = info->a_head;
	if (tmp->prev)
		tmp ->prev->next = NULL;
	else
		info->a_tail = NULL;
	info->a_head = tmp->prev;
	if (!(info->b_head))
	{
		tmp->prev = NULL;
		info->b_tail = tmp;
	}
	else
	{
		info->b_head->next = tmp;
		tmp -> prev = info->b_head;
	}
	info->b_head = tmp;
	info->b_num += 1;
	info -> a_num -= 1;
	print_op(info, "pb\n");
}
