/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:18:08 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 08:00:47 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_info *info, char *string)
{
	if (!(info->checker))
		write(1, string, ft_strlen(string));
}

void	print_stack(t_info *info)
{
	t_stack	*tmp;
	int		data;

	tmp = info->a_head;
	write(1, "\na stack\n", 9);
	while (tmp)
	{
		data = tmp->data;
		write(1, ft_itoa(data), ft_strlen(ft_itoa(data)));
		write(1, " ", 1);
		tmp = tmp->prev;
	}
	tmp = info->b_head;
	write(1, "\nb stack\n", 9);
	while (tmp)
	{
		data = tmp->data;
		write(1, ft_itoa(data), ft_strlen(ft_itoa(data)));
		write(1, " ", 1);
		tmp = tmp->prev;
	}
	write(1, "\n", 1);
}

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	ft_putstr_fd("print arr ", 1);
	while (i < len)
	{
		write(1, ft_itoa(arr[i]), ft_strlen(ft_itoa(arr[i])));
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

static void	print_info_sub(t_stack *stack)
{
	if (stack)
		ft_putnbr_fd(stack->data, 1);
	else
		ft_putstr_fd("NULL", 1);
	ft_putchar_fd('\n', 1);
}

void	print_info(t_info	*info)
{
	ft_putstr_fd("a_head :", 1);
	print_info_sub(info->a_head);
	ft_putstr_fd("a_tail :", 1);
	print_info_sub(info->a_tail);
	ft_putstr_fd("a_num : ", 1);
	ft_putnbr_fd(info->a_num, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b_head :", 1);
	print_info_sub(info->b_head);
	ft_putstr_fd("b_tail :", 1);
	print_info_sub(info->b_tail);
	ft_putstr_fd("b_num : ", 1);
	ft_putnbr_fd(info->b_num, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("len : ", 1);
	ft_putnbr_fd(info->len, 1);
	ft_putchar_fd('\n', 1);
	write(1, "\n", 1);
}
