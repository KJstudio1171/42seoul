/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:51:17 by junekim           #+#    #+#             */
/*   Updated: 2022/08/25 01:22:39 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char *ft_strdup(char *str)
{
	int len = 0;
	int i = 0;
	char *line;
	while(str[len])
	{
		len++;
	}
	line = (char *)malloc(sizeof(char) * (len + 1));
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
	char buf[10000] = {0};
	char c = 0;
	int i = 0;

	while ((read(fd, &c, 1)) > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
	}
	buf[i] = '\0';
	if (buf[0] == '\0')
		return (NULL);
	return ft_strdup(buf);
}
