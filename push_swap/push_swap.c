/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:07:46 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 08:45:57 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	int		*arr;

	if (is_inputable(argc, argv))
	{
		print_error();
		return (0);
	}
	i = argc - 1;
	init_info(&info, argc - 1, 0);
	while (i > 0)
	{
		push_a(&info, new_stack(ft_atoi(argv[i])));
		i--;
	}
	arr = init_arr(&info);
	quicksort_stack_a(&info, info.len);
	free_stacks(&info);
	free(arr);
	return (0);
}
