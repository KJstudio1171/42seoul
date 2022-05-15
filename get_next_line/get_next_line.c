/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:27:32 by junekim           #+#    #+#             */
/*   Updated: 2022/03/21 05:52:57 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
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

char	*read_buf(int fd, char **remain_buf)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!ft_strchr(*remain_buf, '\n'))
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		*remain_buf = ft_strjoin(*remain_buf, buf);
	}
	return (*remain_buf);
}

char	*find_line1(char **remain_buf)
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

char	*find_line2(char **remain_buf)
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

	if (fd < 0 || BUFFER_SIZE <= 0)
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
