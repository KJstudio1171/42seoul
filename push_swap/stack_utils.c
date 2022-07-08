/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:50:56 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 07:59:52 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_info *info, t_stack *stack)
{
	t_stack	*tmp;

	tmp = info->a_head;
	if (!tmp)
	{
		info->a_head = stack;
		info->a_tail = stack;
	}
	else
	{
		tmp -> next = stack;
		stack->prev = tmp;
		stack->next = NULL;
		info->a_head = stack;
	}
	info->a_num += 1;
}

void	push_b(t_info *info, t_stack *stack)
{
	t_stack	*tmp;

	tmp = info->b_head;
	if (!tmp)
	{
		info->b_head = stack;
		info->b_tail = stack;
	}
	else
	{
		tmp -> next = stack;
		stack->prev = tmp;
		stack->next = NULL;
		info->b_head = stack;
	}
	info->b_num += 1;
}

t_stack	*new_stack(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->data = data;
	stack->prev = NULL;
	stack->next = NULL;
	return (stack);
}

void	init_info(t_info *info, int len, int checker)
{
	info->a_head = NULL;
	info->a_tail = NULL;
	info->b_head = NULL;
	info->b_tail = NULL;
	info->a_num = 0;
	info->b_num = 0;
	info->len = len;
	info->checker = checker;
}

void	free_stacks(t_info *info)
{
	t_stack	*tmp;

	info->a_tail = NULL;
	info->b_tail = NULL;
	while (info->a_head)
	{
		tmp = info->a_head;
		info->a_head = info->a_head->prev;
		free(tmp);
		tmp = NULL;
	}
	while (info->b_head)
	{
		tmp = info->b_head;
		info->b_head = info->b_head->prev;
		free(tmp);
		tmp = NULL;
	}
}
