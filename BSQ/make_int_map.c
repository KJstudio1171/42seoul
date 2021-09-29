/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:16:38 by slyu              #+#    #+#             */
/*   Updated: 2021/09/29 22:58:20 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	initialize_int_map(t_map *box)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= box -> row_size)
	{
		x = 0;
		while (x <= box -> column_size)
		{
			box -> int_map[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	make_int_map(t_map *box)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	initialize_int_map(box);
	while (y <= box -> row_size)
	{
		x = 1;
		while (x <= box -> column_size)
		{
			if (box -> map[y - 1][x - 1] == box -> obs)
				plus_one(x, y, box);
			x++;
		}
		y++;
	}
}

void	plus_one(int x, int y, t_map *box)
{
	int	start_x;

	start_x = x;
	while (y <= box -> row_size)
	{
		x = start_x;
		while (x <= box -> column_size)
		{
			box -> int_map[y][x] += 1;
			x++;
		}
		y++;
	}
}

int	check_possible(int x, int y, int size, int **int_map)
{
	int	result;

	result = 0;
	result = int_map[y + size - 1][x + size - 1] - int_map[y + size - 1][x - 1];
	result -= int_map[y - 1][x + size - 1] - int_map[y - 1][x - 1];
	if (result == 0)
		return (1);
	else
		return (0);
}

void	search_biggest(t_map *box)
{
	int	x;
	int	y;
	int	size;
	int	memory[4];

	y = 1;
	size = 1;
	memory[4] = 0;
	while (y + size - 1 <= box -> row_size)
	{
		x = 0;
		while (++x + size - 1 <= box -> column_size && y + size - 1 <= box -> row_size)
			while (check_possible(x, y, size, box -> int_map))
			{
				memory[4] = 1;
				memory[0] = x - 1;
				memory[1] = y - 1;
       			memory[2] = size;
				size++;
				if (y + size - 1 > box -> row_size 
				|| x + size - 1 > box -> column_size)
					break ;
			}
		y++;
	}
	if (memory[4])
		draw_in_map(memory, box);
}

void	draw_in_map(int	*memory, t_map *box)
{
	int	i;
	int	j;

	i = 0;
	while (i < memory[2])
	{
		j = 0;
		while (j < memory[2])
		{
			box -> map[memory[1] + i][memory[0] + j] = box -> square;
			j++;
		}
		i++;
	}
}
