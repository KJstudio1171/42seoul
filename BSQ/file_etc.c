/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:42:40 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 21:07:39 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

char	*copy_map(char *str, t_map *map_arr, int i, int row)
{
	int	index;

	index = 0;
	while (*str != '\n')
	{
		if (*str != map_arr[i].obs && *str != map_arr[i].road
			&& *str != map_arr[i].square)
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

int	find_file_size(int fd)
{
	long long	file_len;
	char		*buf;
	int			read_number;

	file_len = 0;
	read_number = 1;
	buf = (char *)malloc(sizeof(char) * 128);
	if (!buf)
		malloc_error();
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

void	ft_strcpy(char *dest, char *src, int buf_size, int size)
{
	int	i;

	i = 0;
	while (i < buf_size * size)
	{
		dest[i] = src[i];
		i++;
	}
}
