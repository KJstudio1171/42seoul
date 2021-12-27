/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <seongjch@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:42:35 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/19 13:23:29 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	***dynamic_memory_allocation(int n)
{
	int		i;
	int		j;
	char	***map;

	i = 1;
	j = 1;
	map = (char ***)malloc(8 * n);
	map[0] = (char **)malloc(8 * n * n);
	while (i < n)
	{
		map[i] = map[i - 1] + n;
		i++;
	}
	i = 0;
	map[0][0] = (char *)malloc(n * n * 1 * n);
	while (i < n)
	{
		while (j < n)
		{
			map[i][j] = map[i][j - 1] + n ;
			if ( j == n - 1 && i + 1 < n)
				map[i + 1][0] = map[i][j] + n;
			j++;
		}
		j = 1;
		i++;
	}
	return (map);
}

void	dynamic_memory_free(char ***map)
{
	free(map[0][0]);
	free(map[0]);
	free(map);
}

void	init_map(char ***map, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		while (j < n)
		{
			while (k < n)
			{
				map[i][j][k] = '1' + k;
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_map(char ***map, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		while (j < n)
		{
			while (k < n)
			{
				write(1, &map[i][j][k], 1);
				k++;
			}
			write(1, " ", 1);
			k = 0;
			j++;
		}
		write(1,"\n", 1);
		j = 0;
		i++;
	}
}

int		min(int a, int b)
{
	char	min;
	if(a < b)
		min = a;
	else
		min = b;
	return (min);
}

void	first_delete(char ***map,int n,char **argv)
{
	int		i;
	int		j;
	int		k;
	char	num_max;

	i = 0;
	j = 0;
	k = 0;
	num_max = n;
	while (i < n)
	{
		while (j < n)
		{
			num_max = min(num_max, (n - argv[j + 1][0] + '0' + 1 + i));
			num_max = min(num_max, (n - argv[j + n + 1][0] + '0' + 1 + n - 1 - i));
			num_max = min(num_max, (n - argv[i + 2 * n + 1][0] + '0' + 1 + j));
			num_max = min(num_max, (n - argv[i + 3 * n + 1][0] + '0' + 1 + n - 1 - j));
			while (k < n)
			{
				if (num_max < (k + 1))
				{
					map[i][j][k] = 'X';
				}
				k++;
			}
			num_max = n;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void    edit_only_ver(char ***map, int n, int i, int target)
{
	int count[3];

	count[0] = -1;
	while (++count[0] < n)
	{
		count[1] = -1;
		while (++count[1] < n)
		{
			if (map[count[0]][i][count[1]] == target + '0' )
			{
				count[2] = -1;
				while (++count[2] < n)
				{
					if (count[2] != count[1])
						map[count[0]][i][count[2]] = 'X';
				}
			}
		}
	}
}

void    edit_only(char ***map, int n, int i, int target)
{
	int count[3];
		
	count[0] = -1;
	while (++count[0] < n)
	{
		count[1] = -1;
		while (++count[1] < n)
		{
			if (map[i][count[0]][count[1]] == target + '0' )
			{
				count[2] = -1;
				while (++count[2] < n)	
				{
					if (count[2] != count[1])
						map[i][count[0]][count[2]] = 'X';
				}
			}
		}
	}
}

void	box_init(int	*box, int n)
{
	int	count;

	count = -1;
	while (++count < n)
		box[count] = 0;	
}

void	find_only_ver(char ***map, int n)
{
	int	count[4];
	int	*box;

	count[0] = -1;
	while (++count[0] < n)
	{
		box = (int*) malloc(4 * n);
		box_init(box, n);
		count[1] = -1;
		while (++count[1] < n)
		{
			count[2] = -1;
			while (++count[2] < n)
			{
				if (map[count[1]][count[0]][count[2]] == 'X')
					box[count[2]]++;
			}
		}
		count[3] = -1;
		while (++count[3] < n)
		{
			if (box[count[3]] == 3)
			{
				edit_only_ver(map, n, count[0], count[3] + 1);
			}
		}
		free(box);
	}
}

void	find_only(char ***map, int n)
{
	int	count[4];
	int	*box;

	count[0] = -1;
	while (++count[0] < n)
	{
		box = (int*) malloc(4 * n);
		box_init(box, n);
		count[1] = -1;
		while (++count[1] < n)
		{
			count[2] = -1;
			while (++count[2] < n)
			{
				if (map[count[0]][count[1]][count[2]] == 'X')
					box[count[2]]++;
			}
		}
		count[3] = -1;
		while (++count[3] < n)
		{
			if (box[count[3]] == 3)
			{
				edit_only(map, n, count[0], count[3] + 1);
			}
		}
		free(box);
	}
}

void	resolved_del(char	***map, int	n, int	i, int	j)
{
	 int	count[4];
	char	target;

	count[0] = -1;
	while (++count[0] < n)
	{
		if (map[i][j][count[0]] != 'X')
			target = map[i][j][count[0]];
	}
	count[1] = -1;
	while (++count[1] < n)
	{
		if (count[1] != j)
		{
			count[2] = -1;
			while (++count[2] < n)
			{
				if (map[i][count[1]][count[2]] == target)
					map[i][count[1]][count[2]] = 'X';
			}
		}
		if (count[1] != i)
		{
			count[3] = -1;
			while (++count[3] < n)
			{
				if (map[count[1]][j][count[3]] == target)
					map[count[1]][j][count[3]] = 'X';
			}	
		}
	}
}
void	resolved_find(char	***map, int n)
{
	int count[4];

	count[0] = -1;
	count[3] = 0;
	while (++count[0] < n)
	{
		count[1] = -1;
		while (++count[1] < n)
		{
			count[2] = -1;
			while (++count[2] < n)
			{
				if (map[count[0]][count[1]][count[2]] != 'X')
					count[3]++;
			}
			if (count[3] == 1)
					resolved_del(map, n, count[0], count[1]);
			count[3] = 0;
		}
	}
}
int	main(void)
{
	int		argc = 17;
	char	*argv[17] = {"./a.out","4", "3", "2", "1", "1", "2", "2", "2", "4", "3", "2", "1", "1", "2", "2", "2"};
	int		n = (argc - 1) / 4;
	char	***map = dynamic_memory_allocation(n);

	init_map(map, n);
	first_delete(map, n, argv);
	print_map(map, n);
	resolved_find(map, n);
	print_map(map, n);
	find_only(map, n);
	print_map(map, n);
	find_only_ver(map, n);
	print_map(map, n);
	dynamic_memory_free(map);
}
