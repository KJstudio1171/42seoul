/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:44:29 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:50:34 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	expand_buf(char **stdin_file, int file_buf_size, int size)
{
	char	*expand;
	char	*tmp;

	expand = (char *) malloc(sizeof(char) * file_buf_size * size);
	if (!expand)
		malloc_error();
	ft_strcpy(expand, *stdin_file, file_buf_size, size - 1);
	tmp = *stdin_file;
	*stdin_file = expand;
	free(tmp);
}

char	*read_stdin_file(int *file_len, char *buf)
{
	char	*stdin_file;
	int		read_number;
	int		file_buf_size;
	int		i;
	int		n;

	file_buf_size = 128;
	stdin_file = (char *)malloc(sizeof (char) * file_buf_size);
	if (!stdin_file)
		malloc_error();
	i = 0;
	n = 1;
	read_number = 1;
	while (read_number > 0)
	{
		if (i == file_buf_size * n)
			expand_buf(&stdin_file, file_buf_size, ++n);
		read_number = read(0, buf, 1);
		stdin_file[i++] = buf[0];
		(*file_len)++;
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
	int	c_size;
	int	r_size;
	int	index;

	c_size = line_len(str + 1);
	r_size = map_arr[i].row_size;
	index = 1;
	map_arr[i].column_size = c_size;
	if (!is_map(map_arr, i))
	{
		map_error(map_arr, i);
		return ;
	}
	map_arr[i].map = (char **)malloc(sizeof(char *) * r_size);
	if (!map_arr[i].map)
		malloc_error();
	map_arr[i].map[0] = (char *)malloc(sizeof(char) * r_size * c_size);
	if (!map_arr[i].map[0])
		malloc_error();
	while (index <= r_size)
	{
		map_arr[i].map[index] = map_arr[i].map[index - 1] + c_size;
		str = copy_map(str + 1, map_arr, i, index - 1);
		if (str == NULL)
			return ;
		index++;
	}
	index = 1;
	map_arr[i].int_map = (int **)malloc(sizeof(int *) * (r_size + 1));
	if (!map_arr[i].int_map)
		malloc_error();
	map_arr[i].int_map[0] = (int *)malloc(sizeof(int) * (r_size + 1) * (c_size + 1));
	if (!map_arr[i].int_map[0])
		malloc_error();
	while (index <= r_size + 1)
	{
		map_arr[i].int_map[index] = map_arr[i].int_map[index - 1] + c_size + 1;
		index++;
	}
}

char	*read_file(int fd, int file_len)
{
	char	*buf;
	int		read_number;

	buf = (char *)malloc(sizeof(char) * (file_len + 1));
	if (!buf)
		malloc_error();
	read_number = read(fd, buf, file_len);
	if (read_number == -1)
		file_read_error();
	return (buf);
}
