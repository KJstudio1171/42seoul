/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:38:21 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 11:21:02 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_map.h"
#include "ft_error.h"
#include "ft_file_io.h"
#include "make_int_map.h"

t_map	*ft_open_argv(int argc, char **argv) // argc==1일때
{
	t_map	*map_arr;
	int		i;

	map_arr = (t_map *)malloc(sizeof(t_map) * (argc - 1));
	i = 0;
	while (i < argc - 1)
	{
		ft_open_file(argv, i++, map_arr);
	}
	return (map_arr);
}

void	ft_print_map(t_map *map_arr, int i)//삭제요망
{
	int	index;

	index = 0;
	while (index < map_arr[i].row_size)
	{
		write(1, map_arr[i].map[index++], map_arr[i].column_size);
		write(1, "\n", 1);
	}
}

void	ft_open_file(char **argv, int i, t_map *map_arr)
{
	int		fd;
	int		file_size;
	int		map_start;
	char	*file_type_str;

	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		ft_file_open_error();
	file_size = ft_find_file_size(fd);
	close(fd);
	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		ft_file_open_error();
	file_type_str = ft_read_file(fd, i, file_size);
	map_start = ft_read_info(file_type_str, map_arr, i);
	if (file_size <= map_start + 1)
		ft_map_error();
	ft_read_map(file_type_str + map_start, map_arr, i);
	close(fd);
}

char	*ft_malloc_line(int size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * size);
	return (buffer);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_find_file_size(int fd)
{
	long long	file_size;
	char		*buf;
	int			read_number;

	file_size = 0;
	read_number = 1;
	buf = (char *)malloc(sizeof(char) * 128);
	while (read_number > 0)
	{
		read_number = read(fd, buf, sizeof(buf));
		file_size += read_number;
	}
	if (read_number == -1)
		ft_file_read_error();
	return (file_size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_read_file(int fd, int i, int file_size)
{
	int		column_len;
	char	*buf;
	int		read_number;

	buf = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!buf)
		ft_malloc_error();
	read_number = read(fd, buf, file_size);
	if (read_number == -1)
		ft_file_read_error();
	return (buf);
}

int	ft_read_info(char *str, t_map *map_arr, int i)
{
	int	info_len;
	int	index;

	info_len = ft_line_len(str);
	index = info_len;
	if (index < 4)
		ft_info_error();
	map_arr[i].square = str[--index];
	map_arr[i].obs = str[--index];
	map_arr[i].road = str[--index];
	map_arr[i].row_size = 0;
	index = 0;
	while (index < info_len - 3)
	{
		if (str[index] >= '0' && str[index] <= '9')	//??
		{
			map_arr[i].row_size *= 10;
			map_arr[i].row_size += str[index] - '0';
		}
		else
			ft_info_error();
		index++;
	}
	return (info_len);
}

void	ft_read_map(char *str, t_map *map_arr, int i)
{
	int	column_size;
	int	row_size;
	int	index;

	column_size = ft_line_len(str + 1);
	row_size = map_arr[i].row_size;
	index = 1;
	map_arr[i].column_size = column_size;
	map_arr[i].map = (char **)malloc(sizeof(char *) * row_size);
	map_arr[i].map[0] = (char *)malloc(sizeof(char) * row_size * column_size);
	while (index <= row_size)
	{
		map_arr[i].map[index] = map_arr[i].map[index - 1] + column_size;
		str = ft_copy_map(str + 1, map_arr, i, index - 1);
		index++;
	}
	index = 1;
	map_arr[i].int_map = (int **)malloc(sizeof(int *) * (row_size + 1));
	map_arr[i].int_map[0] = (int *)malloc(sizeof(int) * (row_size + 1) * (column_size + 1));
	while (index <= row_size + 1)
	{
		map_arr[i].int_map[index] = map_arr[i].int_map[index - 1] + column_size + 1;
		index++;
	}
}

char	*ft_copy_map(char *str, t_map *map_arr,int i, int row)
{
	int	index;

	index = 0;
	while (*str != '\n')
	{
		map_arr[i].map[row][index] = *str;
		str++;
		index++;
	}
	return (str);
}
//맵 에러검사

int	ft_line_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

int main(int argc, char **argv)
{
	t_map	*map_arr;
	int		i;

	i = 0;
	map_arr = ft_open_argv(argc, argv);
	while (i < argc - 1)
	{
		make_int_map(&map_arr[i]);
		search_biggest(&map_arr[i++]);
	}
	i = 0;
	while (i < argc - 1)
	{
		ft_print_map(map_arr, i++);
	}
	return (0);
}
