/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 01:10:28 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 07:55:24 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + len_s2 + 1);
	ft_strlcat(ptr, s2, len_s1 + len_s2 + 1);
	free(s1);
	return (ptr);
}

static char	*read_buf(int fd, char **remain_buf)
{
	char	buf[8 + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!ft_strchr(*remain_buf, '\n'))
	{
		read_bytes = read(fd, buf, 8);
		if (read_bytes < 0)
			return (NULL);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		*remain_buf = ft_strjoin2(*remain_buf, buf);
	}
	return (*remain_buf);
}

static char	*find_line1(char **remain_buf)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while ((*remain_buf)[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while ((*remain_buf)[i] != '\n')
	{
		line[i] = (*remain_buf)[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	tmp = ft_strdup(&((*remain_buf)[i + 1]));
	free(*remain_buf);
	*remain_buf = tmp;
	return (line);
}

static char	*find_line2(char **remain_buf)
{
	int		i;
	char	*line;

	i = 0;
	while ((*remain_buf)[i])
		i++;
	if (i == 0)
	{
		free (*remain_buf);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while ((*remain_buf)[i])
	{
		line[i] = (*remain_buf)[i];
		i++;
	}
	line[i + 1] = '\0';
	free(*remain_buf);
	*remain_buf = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain_buf;
	char		*line;

	if (fd < 0 || 8 <= 0)
		return (0);
	remain_buf = read_buf(fd, &remain_buf);
	if (!remain_buf)
		return (NULL);
	if (ft_strchr(remain_buf, '\n'))
		line = find_line1(&remain_buf);
	else
		line = find_line2(&remain_buf);
	return (line);
}
