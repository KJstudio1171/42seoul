/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:21:16 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 20:31:40 by junekim          ###   ########seoul.kr  */
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
	if(map_arr[i].error != 1)
	{
		while (index < map_arr[i].row_size)
		{
			write(1, map_arr[i].map[index++], map_arr[i].column_size);
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
	}
}

void	open_file(char **argv, int i, t_map *map_arr)
{
	int		fd;
	int		file_len;
	int		info_len;
	char	*file_str_type;

	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_len = find_file_size(fd);
	close(fd);
	fd = open(argv[i + 1], O_RDONLY);
	if (fd < 0)
		file_open_error();
	file_str_type = read_file(fd, file_len);
	info_len = read_info(file_str_type, map_arr, i);
	if (file_len <= info_len + 1)
	{
		map_error(map_arr, i);
		return ;
	}
	map_arr[i].info_len = info_len;
	map_arr[i].file_len = file_len;
	read_map(file_str_type + info_len, map_arr, i);
	close(fd);
}

void	open_stdin_file(char **argv, t_map *map_arr)
{
	int		info_len;
	int		file_len;
	char	*file_str_type;

	file_len = 0;
	file_str_type = read_stdin_file(&file_len);
	info_len = read_info(file_str_type, map_arr, 0);
	if (file_len <= info_len + 1)
	{
		map_error(map_arr, 0);
		exit(1);
	}
	map_arr[0].info_len = info_len;
	map_arr[0].file_len = file_len;
	read_map(file_str_type + info_len, map_arr, 0);
}

char	*malloc_line(int size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * size);
	return (buffer);
}

int	find_file_size(int fd)
{
	long long	file_len;
	char		*buf;
	int			read_number;

	file_len = 0;
	read_number = 1;
	buf = (char *)malloc(sizeof(char) * 128);
	while (read_number > 0)
	{
		read_number = read(fd, buf, sizeof(buf));
		file_len += read_number;
	}
	if (read_number == -1)
		file_read_error();
	free(buf);
	return (file_len);
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

void	expand_buf(char **stdin_file,int file_buf_size, int size)
{
	char	*expand;
	char	*tmp;

	expand = (char *) malloc(sizeof(char) * file_buf_size * size);
	ft_strcpy(expand, *stdin_file, file_buf_size, size - 1);
	tmp = *stdin_file;
	*stdin_file = expand;
	free(tmp);
}

char	*read_stdin_file(int *file_len)
{
	char	buf[1];
	char	*stdin_file;
	int		read_number;
	int		file_buf_size;
	int		i;
	int		n;

	file_buf_size = 128;
	stdin_file = (char *)malloc(sizeof (char) * file_buf_size);
	i = 0;
	n = 1;
	read_number = 1;
	if (!stdin_file)
		malloc_error();
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

int	is_printable(char ch)
{
	if (32 < ch && 126 > ch)
		return (1);
	return (0);
}

int	is_map(t_map *map_arr, int i)
{
	char	obs;
	char	road;
	char	square;
	char	map_len;

	obs = map_arr[i].obs;
	road = map_arr[i].road;
	square = map_arr[i].square;
	map_len = map_arr[i].file_len - map_arr[i].info_len - 1;
	if (obs == road || road == square || square == obs)
	{
		map_error(map_arr, i);
		return (0);
	}
	if (!is_printable(obs) || !is_printable(road) || !is_printable(square))
	{
		map_error(map_arr, i);
		return (0);
	}
	if (map_arr[i].row_size != map_len / (map_arr[i].column_size + 1))
	{
		map_error(map_arr, i);
		return (0);
	}
	return (1);
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
	if (!is_map(map_arr, i))
	{
		 map_error(map_arr, i);
		return ;
	}
	map_arr[i].map = (char **)malloc(sizeof(char *) * row_size);
	map_arr[i].map[0] = (char *)malloc(sizeof(char) * row_size * column_size);
	while (index <= row_size)
	{
		map_arr[i].map[index] = map_arr[i].map[index - 1] + column_size;
		str = copy_map(str + 1, map_arr ,i ,index - 1);
		if (str == NULL)
			return ;
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

char	*copy_map(char *str, t_map *map_arr, int i, int row)
{
	int	index;

	index = 0;
	while (*str != '\n')
	{
		if (*str != map_arr[i].obs && *str != map_arr[i].road && *str != map_arr[i].square)
		{
			map_error(map_arr, i);
			return (NULL);
		}
		map_arr[i].map[row][index] = *str;
		str++;
		index++;
	}
	if (index != map_arr[i].column_size)
	{
		map_error(map_arr, i);
		return (NULL);
	}
	return (str);
}
//맵 에러검사

int	line_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
	{
		if (len == 2147483647)
			overflow_error();
		len++;
	}
	return (len);
}
