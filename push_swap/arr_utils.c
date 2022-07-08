/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 07:30:27 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 07:56:21 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quicksort_arr(int *arr, int l, int r)
{
	int	left;
	int	right;
	int	pivot;

	left = l;
	right = r;
	pivot = arr[(l + r) / 2];
	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			if (left != right)
				swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
		if (left < r)
			quicksort_arr(arr, left, r);
		if (right > l)
			quicksort_arr(arr, l, right);
	}
}

int	*init_arr(t_info *info)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	arr = (int *)malloc(sizeof(int) * info->a_num);
	if (!arr && info->a_num != 0)
	{
		free_stacks(info);
		print_error();
	}
	i = 0;
	tmp = info->a_head;
	while (tmp)
	{
		arr[i] = tmp->data;
		tmp = tmp->prev;
		i++;
	}
	quicksort_arr(arr, 0, info->a_num - 1);
	info->sorted_arr = arr;
	return (arr);
}
