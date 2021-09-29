/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:21:16 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 17:42:43 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"
#include <stdio.h>

t_map	*open_argv(int argc, char **argv) // argc==1일때
{
	t_map	*map_arr;
	int		i;

	if (argc == 1)
	{
		map_arr = (t_map *)malloc(sizeof(t_map));
		open_stdin_file(argv, map_arr);
	}
	else
	{
		map_arr = (t_map *)malloc(sizeof(t_map) * (argc - 1));
		i = 0;
		while (i < argc - 1)
		{
			open_file(argv, i++, map_arr);
		}
	}
	return (map_arr);
}

void	print_map(t_map *map_arr, int i)//삭제요망
{
	int	index;

	index = 0;
	while (index < map_arr[i].row_size)
	{
		write(1, map_arr[i].map[index++], map_arr[i].column_size);
		write(1, "\n", 1);
	}
}

void	open_file(char **argv, int i, t_map *map_arr)
{
	int		fd;
	int		file_size;
	int		map_start;
	char	*file_str_type;

	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_size = find_file_size(fd);
	close(fd);
	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_str_type = read_file(fd, file_size);
	map_start = read_info(file_str_type, map_arr, i);
	if (file_size <= map_start + 1)
		map_error();
	read_map(file_str_type + map_start, map_arr, i);
	close(fd);
}

void	open_stdin_file(char **argv, t_map *map_arr)
{
	int		map_start;
	char	*file_str_type;

	file_str_type = read_stdin_file();
	map_start = read_info(file_str_type, map_arr, 0);
	//if (file_size <= map_start + 1)
		//map_error();
	read_map(file_str_type + map_start, map_arr, 0);
}

char	*malloc_line(int size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * size);
	return (buffer);
}

int	find_file_size(int fd)
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
		file_read_error();
	free(buf);
	return (file_size);
}

char	*read_file(int fd, int file_size)
{
	char	*buf;
	int		read_number;

	buf = (char *)malloc(sizeof(char) * (file_size + 1));
	if (!buf)
		malloc_error();
	read_number = read(fd, buf, file_size);
	if (read_number == -1)
		file_read_error();
	return (buf);
}

void	ft_strcpy(char* dest, char *src, int buf_size, int size)
{
	int	i;

	i = 0;
	while (i < buf_size * size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	expand_buf(char **stdin_file,int file_size, int size)
{
	char	*expand;
	char	*tmp;

	expand = (char *) malloc(sizeof(char) * file_size * size);
	ft_strcpy(expand, *stdin_file, file_size, size - 1);
	tmp = *stdin_file;
	*stdin_file = expand;
	free(tmp);
}

char	*read_stdin_file(void)
{
	char	buf[1];
	char	*stdin_file;
	int		read_number;
	int		file_size;
	int		i;
	int		n;

	file_size = 128;
	stdin_file = (char *)malloc(sizeof (char) * file_size);
	i = 0;
	n = 1;
	if (!stdin_file)
		malloc_error();
	while (read_number > 0)
	{
		if (i == file_size * n)
			expand_buf(&stdin_file, file_size, ++n);
		read_number = read(0, buf, 1);
		stdin_file[i++] = buf[0];
	}
	if (read_number == -1)
		file_read_error();
	return (stdin_file);
}

int	read_info(char *str, t_map *map_arr, int i)
{
	int	info_len;
	int	index;

	info_len = line_len(str);
	index = info_len;
	if (index < 4)
		info_error();
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
			info_error();
		index++;
	}
	return (info_len);
}

void	read_map(char *str, t_map *map_arr, int i)
{
	int	column_size;
	int	row_size;
	int	index;

	column_size = line_len(str + 1);
	row_size = map_arr[i].row_size;
	index = 1;
	map_arr[i].column_size = column_size;
	map_arr[i].map = (char **)malloc(sizeof(char *) * row_size);
	map_arr[i].map[0] = (char *)malloc(sizeof(char) * row_size * column_size);
	while (index <= row_size)
	{
		map_arr[i].map[index] = map_arr[i].map[index - 1] + column_size;
		str = copy_map(str + 1, map_arr, i, index - 1);
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

char	*copy_map(char *str, t_map *map_arr,int i, int row)
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

int	line_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}
