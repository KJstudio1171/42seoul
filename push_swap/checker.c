/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:09:53 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 09:22:21 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	if ((ft_strlen(str1) - 1) != ft_strlen(str2))
		return (1);
	while (i < ft_strlen(str2))
	{
		if (s1[i] != s2[i] || !s1[i] || !s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static void	op_execution(t_info *info, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(info);
	else if (!ft_strcmp(line, "sb"))
		sb(info);
	else if (!ft_strcmp(line, "ss"))
		ss(info);
	else if (!ft_strcmp(line, "pa"))
		pa(info);
	else if (!ft_strcmp(line, "pb"))
		pb(info);
	else if (!ft_strcmp(line, "ra"))
		ra(info);
	else if (!ft_strcmp(line, "rb"))
		rb(info);
	else if (!ft_strcmp(line, "rr"))
		rr(info);
	else if (!ft_strcmp(line, "rra"))
		rra(info);
	else if (!ft_strcmp(line, "rrb"))
		rrb(info);
	else if (!ft_strcmp(line, "rrr"))
		rrr(info);
	else
		print_error();
}

static void	print_is_sorted(t_info *info)
{
	if (is_sorted(info))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	int		*arr;
	char	*line;
	t_info	info;

	if (is_inputable(argc, argv))
		print_error();
	i = argc - 1;
	init_info(&info, argc - 1, 0);
	while (i > 0)
		push_a(&info, new_stack(ft_atoi(argv[i--])));
	arr = init_arr(&info);
	line = get_next_line(0);
	while (line)
	{
		op_execution(&info, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	print_is_sorted(&info);
	free_stacks(&info);
	free(arr);
	return (0);
}
