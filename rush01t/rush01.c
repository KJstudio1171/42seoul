/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:42:35 by seongjch          #+#    #+#             */
/*   Updated: 2021/09/19 23:37:50 by junekim          ###   ########.fr       */
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

void	edit_only(char ***map, int n, int i, int target)
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
			if (box[count[3]] == n - 1)
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
			if (box[count[3]] == n - 1)
			{
				edit_only(map, n, count[0], count[3] + 1);
			}
		}
		free(box);
	}
}


void	resolved_del_2(char	***map, int	n, int	i, int	j)
{
	int	index;
	int	target;

	index = 0;
	target = 0;

	while(target < n)
	{
		if(map[i][j][target]=='F')
			break;
		target += 1;
	}
	
	while(index < n)
	{
		if(map[index][j][target]=='F' 
		&& i != index)
			map[index][j][target] = 'X';
		index++;
	}
	index = 0;
	while(index < n)
	{
		if(map[i][index][target]=='F'
		&& j != index)
			map[i][index][target]= 'X';
		index++;
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

void	resolved_find_2(char	***map, int n)
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
				resolved_del_2(map, n, count[0], count[1]);
			count[3] = 0;
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

int	checker_sub(char	*may, int	n)
{
	int	count;
	int	check;
	int	box;

	count = n - 1;
	check = n - 1;
	box = 1;
	while (count > 0)
	{
		if (may[check] < may[count - 1])
		{
			box++;
			check = count - 1;
		}
		count--;
	}
	return (box);
}

int	column_checker(char	*may, char **argv, int j, int n)
{
	int	count;
	int	box;
	int	check;
	int	result;

	box = 1;
	count = -1;
	check = 0;
	result = 0;
	while (++count < n)
	{
		if (may[check] < may[count + 1])
		{
			box++;
			check = count + 1;
		}
	}
	if (box == argv[j + 1][0] - '0')
		result = 1;
	box = checker_sub(may, n);
	if (box == (argv[j + n + 1][0] - '0') && result)
		result = 1;
	else
		result = 0;
	return (result);
}

int	row_checker(char	*may, char **argv, int i, int n)
{
	int	count;
	int	box;
	int	check;
	int	result;

	box = 1;
	count = -1;
	check = 0;
	result = 0;
	while (++count < n)
	{
		if (may[check] < may[count + 1])
		{
			box++;
			check = count + 1;
		}
	}
	if (box == argv[i + 2 * n + 1][0] - '0')
		result = 1;
	box = checker_sub(may, n);
	if (box == (argv[i + 3 * n + 1][0] - '0') && result)
		result = 1;
	else
		result = 0;
	return (result);
}

void column_dfs (char** argv, char ***map, char *testslot, int i, int j ,int n)
{
	int overlap = 0;
	int	k = 0;
	int	row_num = 0;

	if (i == n)
	{
		if (column_checker(testslot, argv, j, n)) // test
		{
			while (row_num < n)
			{
				map[row_num][j][testslot[row_num]] = 'T';
				row_num++;
			}
			return ;
		}
		return ;
	}
	while (k < n)
	{
		if (map[i][j][k] != 'X')
		{
			while(overlap < i)
			{
				if(testslot[overlap] == k)
					break ;
				overlap++;
			}
			if(overlap == i)
			{
				testslot[i] = k;
				column_dfs(argv, map, testslot, i+1,j, n);
			}
		}
		k++;
	}
}

void	column_test(char** argv, char ***map, char *testslot, int n)
{
	int	j;

	j = 0;
	while (j < n)
	{
		column_dfs(argv, map, testslot, 0, j, n);
		j++;
	}
}

void row_dfs (char** argv, char ***map, char *testslot, int i, int j ,int n)
{
	int overlap = 0;
	int	k = 0;
	int	column_num = 0;

	if (j == n)
	{
		if (row_checker(testslot, argv, i , n)) // test
		{
			while (column_num  < n)
			{
				map[i][column_num][testslot[column_num]] = 'F';
				column_num ++;
			}
			return ;
		}
		return ;
	}
	while (k < n)
	{
		if (map[i][j][k] == 'T' || map[i][j][k] == 'F')
		{
			while(overlap < j)
			{
				if(testslot[overlap] == k)
					break ;
				overlap++;
			}
			if(overlap == j)
			{
				testslot[j] = k;
				row_dfs(argv, map, testslot, i, j+1, n);
			}
		}
		k++;
	}
}

void	row_test(char** argv, char ***map, char *testslot, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		row_dfs(argv, map, testslot, i, 0, n);
		i++;
	}
}

void print_final(char ***map,int n)
{


}

void resolve2(char ***map,int n)
{
	int i =0;
	int j =0;
	int k =0;

	while(i<n)
	{
		while(j<n)
		{
			while(k<n)
			{
				if(map[i][j][k]!='F')
					map[i][j][k] = 'X';
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void last_print(char ***map,int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	char number[1];

	while(i<n)
	{
		while(j<n)
		{
			while(k<n)
			{
				if(map[i][j][k]=='F')
				{   
					while(l<n)
					{	if( map[l][j][k] == 'F' && l !=i)
							map[l][j][k] = 'X';
						l++;
					}
					l = 0;
					while(m < n)
					{	if( map[i][m][k] == 'F' && m !=j)
							map[i][m][k] = 'X';
						m++;
					}
					m = 0;

					number[0] = k+1+'0';
					write(1,number,1);
					if(j == n-1)
						write(1,"\n",1);
					else
						write(1," ",1);
				}
					
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
int	main(int argc, char** argv)
{
	int		n = (argc - 1) / 4;
	char	***map = dynamic_memory_allocation(n);
	char * testslot;

	testslot = (char*)malloc(n);
	init_map(map, n);
	first_delete(map, n, argv);	
	find_only(map, n);
	find_only_ver(map, n);
	resolved_find(map, n);
	column_test(argv, map,testslot,n);
	row_test(argv, map,testslot,n);
	resolve2(map,n);
	resolved_find_2(map, n);
	last_print(map, n);
	dynamic_memory_free(map);
	free(testslot);
}
