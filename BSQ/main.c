/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:39:37 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:39:04 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

int	main(int argc, char **argv)
{
	t_map	*map_arr;

	map_arr = open_argv(argc, argv);
	write(1, "\n", 1);
	int_map_print(argc, argv, map_arr);
	//map_inside_free(map_arr, argc);
	//map_free(map_arr);
	return (0);
}
