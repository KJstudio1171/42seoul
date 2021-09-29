/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:39:37 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 15:29:22 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int	main(int argc, char **argv)
{
	t_map	*map_arr;
	int		i;

	i = 0;
	map_arr = open_argv(argc, argv);
	while (i < argc - 1)
	{
		make_int_map(&map_arr[i]);
		search_biggest(&map_arr[i++]);
	}
	i = 0;
	while (i < argc - 1)
	{
		print_map(map_arr, i++);
	}
	return (0);
}
