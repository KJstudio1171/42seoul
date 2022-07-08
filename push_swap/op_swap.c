/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:28:12 by junekim           #+#    #+#             */
/*   Updated: 2022/07/07 23:25:24 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	t_stack	*tmp;

	if (!(info->a_head && info->a_head->prev))
		return ;
	tmp = info->a_head->prev;
	info->a_head->prev = tmp->prev;
	info->a_head->next = tmp;
	tmp->next = NULL;
	if (tmp->prev)
		tmp->prev->next = info->a_head;
	tmp->prev = info->a_head;
	info->a_head = tmp;
	print_op(info, "sa\n");
}

void	sb(t_info *info)
{
	t_stack	*tmp;

	if (!(info->b_head && info->b_head->prev))
		return ;
	tmp = info->b_head->prev;
	info->b_head->prev = tmp->prev;
	info->b_head->next = tmp;
	tmp->next = NULL;
	if (tmp->prev)
		tmp->prev->next = info->b_head;
	tmp->prev = info->b_head;
	info->b_head = tmp;
	print_op(info, "sb\n");
}

void	ss(t_info *info)
{
	t_stack	*tmp;

	if (!(info->a_head && info->b_head
			&& info->a_head->prev && info->b_head->prev))
		return ;
	tmp = info->a_head->prev;
	info->a_head->prev = tmp->prev;
	info->a_head->next = tmp;
	tmp->next = NULL;
	if (tmp->prev)
		tmp->prev->next = info->a_head;
	tmp->prev = info->a_head;
	info->a_head = tmp;
	tmp = info->b_head->prev;
	info->b_head->prev = tmp->prev;
	info->b_head->next = tmp;
	tmp->next = NULL;
	if (tmp->prev)
		tmp->prev->next = info->b_head;
	tmp->prev = info->b_head;
	info->b_head = tmp;
	print_op(info, "ss\n");
}
