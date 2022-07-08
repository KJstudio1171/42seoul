/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:55:48 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 01:15:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info	*info)
{
	t_stack	*tmp;

	tmp = info->a_head;
	if (!(tmp && tmp->prev))
		return ;
	tmp->prev->next = NULL;
	info->a_head = tmp->prev;
	info->a_tail->prev = tmp;
	tmp->next = info->a_tail;
	tmp ->prev = NULL;
	info->a_tail = tmp;
	print_op(info, "ra\n");
}

void	rb(t_info	*info)
{
	t_stack	*tmp;

	tmp = info->b_head;
	if (!(tmp && tmp->prev))
		return ;
	tmp->prev->next = NULL;
	info->b_head = tmp->prev;
	info->b_tail->prev = tmp;
	tmp->next = info->b_tail;
	tmp ->prev = NULL;
	info->b_tail = tmp;
	print_op(info, "rb\n");
}

void	rr(t_info	*info)
{
	t_stack	*tmp;

	if (!(info->a_head && info->b_head
			&& info->a_head->prev && info->b_head->prev))
		return ;
	tmp = info->a_head;
	tmp->prev->next = NULL;
	info->a_head = tmp->prev;
	info->a_tail->prev = tmp;
	tmp->next = info->a_tail;
	tmp ->prev = NULL;
	info->a_tail = tmp;
	tmp = info->b_head;
	tmp->prev->next = NULL;
	info->b_head = tmp->prev;
	info->b_tail->prev = tmp;
	tmp->next = info->b_tail;
	tmp ->prev = NULL;
	info->b_tail = tmp;
	print_op(info, "rr\n");
}
