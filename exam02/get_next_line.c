/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:34:21 by junekim           #+#    #+#             */
/*   Updated: 2022/08/25 01:07:00 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while(*str)
	{
		i++;
		str++;
	}
	return i;
}

char	*ft_strdup(char *str)
{
	int len = ft_strlen(str);
	int i = 0;
	char *line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	
	while(str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	buf[9999] = {0};
	char	c;
	int	i = 0;
	int j = 0;

	while ((j = read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
		{
			buf[i] = '\0';
			break ;
		}
	}
	if (buf[0] == 0)
		return (NULL);
	return ft_strdup(buf);
}