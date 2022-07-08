/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:02:39 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 08:26:31 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_stack	*tmp;

	tmp = info->a_tail;
	if (!(tmp && tmp->next))
		return ;
	tmp->next->prev = NULL;
	info->a_tail = tmp->next;
	info->a_head->next = tmp;
	tmp->prev = info->a_head;
	tmp->next = NULL;
	info->a_head = tmp;
	print_op(info, "rra\n");
}

void	rrb(t_info *info)
{
	t_stack	*tmp;

	tmp = info->b_tail;
	if (!(tmp && tmp->next))
		return ;
	tmp->next->prev = NULL;
	info->b_tail = tmp->next;
	info->b_head->next = tmp;
	tmp->prev = info->b_head;
	tmp->next = NULL;
	info->b_head = tmp;
	print_op(info, "rrb\n");
}

void	rrr(t_info *info)
{
	t_stack	*tmp;

	if (!(info->a_tail && info->b_tail
			&& info->a_tail->next && info->b_tail->next))
		return ;
	tmp = info->a_tail;
	tmp->next->prev = NULL;
	info->a_tail = tmp->next;
	info->a_head->next = tmp;
	tmp->prev = info->a_head;
	tmp->next = NULL;
	info->a_head = tmp;
	tmp = info->b_tail;
	tmp->next->prev = NULL;
	info->b_tail = tmp->next;
	info->b_head->next = tmp;
	tmp->prev = info->b_head;
	tmp->next = NULL;
	info->b_head = tmp;
	print_op(info, "rrr\n");
}
