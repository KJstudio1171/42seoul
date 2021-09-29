/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_int_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:16:38 by slyu              #+#    #+#             */
/*   Updated: 2021/09/29 00:53:32 by slyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	plus_one(int x, int y,t_map *box);
void	draw_in_map(int	*memory, t_map *box);

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

void search_biggest(t_map *box)
{
	int	x;
	int	y;
	int	size;
	int	memory[3];
	int	check;

	x = 1;
	y = 1;
	size = 1;
	while (y + size <= box -> row_size)
	{
		while (x + size <= box -> column_size && y + size <= box -> row_size)
		{
			check = 0;
			while (check_possible(x, y, size, box -> int_map))
			{	
				check = 1;
				size++;
				if (y + size > box -> row_size || x + size > box -> column_size)
					break ;
			}
			if (check)
			{
				memory[0] = x - 1;
				memory[1] = y - 1;
				memory[2] = size - 1;
			}
			x++;
		}
		y++;
	}
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
