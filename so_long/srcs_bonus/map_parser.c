/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:08:33 by junekim           #+#    #+#             */
/*   Updated: 2022/08/19 18:39:14 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(ptr, s1, len_s1 + len_s2 + 1);
	ft_strlcat(ptr, s2, len_s1 + len_s2 + 1);
	free(s1);
	free(s2);
	return (ptr);
}

static void	is_map_sub(t_game_manager *gm, char	*ptr, int fd)
{
	if (*ptr != 'C' && *ptr != 'E' && *ptr != 'P'
		&& *ptr != 'e' && *ptr != '1' && *ptr != '0')
		map_error(NO_MAP, fd, gm);
	if (*ptr == 'C')
		gm -> map_info -> collectible += 1;
	else if (*ptr == 'E')
		gm -> map_info -> exit += 1;
	else if (*ptr == 'P')
		gm -> map_info -> start_position += 1;
	else if (*ptr == 'e')
		gm -> map_info -> enemy += 1;
}

static void	is_map(t_game_manager *gm, int fd)
{
	char	*ptr;
	size_t	i;

	ptr = gm->map_info->map_string;
	i = 0;
	while (i < gm->map_info->width)
	{
		if (ptr[i] != '1' || ptr[ft_strlen(ptr) - 1 - i] != '1')
			map_error(NO_WALL, fd, gm);
		i++;
	}
	while (*ptr)
	{
		is_map_sub(gm, ptr, fd);
		ptr++;
	}
	if (gm -> map_info -> collectible == 0)
		map_error(NO_COLLECTIBLE, fd, gm);
	else if (gm -> map_info -> exit == 0)
		map_error(NO_EXIT, fd, gm);
	else if (gm -> map_info -> start_position != 1)
		map_error(NO_START_POSITION, fd, gm);
}

static	void	map_parser_sub(int fd, char **line, t_game_manager *gm)
{
	t_map_info	*map_info;

	map_info = gm->map_info;
	map_info->height++;
	map_info->map_string = ft_strjoin2(map_info->map_string, *line);
	*line = get_next_line(fd);
	if (*line && (*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	if (*line)
	{
		if (ft_strlen(*line) != map_info->width)
			map_error(NO_RECTANGULAR, fd, gm);
		if ((*line)[0] != '1' || (*line)[map_info->width - 1] != '1')
			map_error(NO_WALL, fd, gm);
	}
}

void	map_parser(t_game_manager *gm, char *file_name)
{
	int			fd;
	char		*line;
	t_map_info	*map_info;

	map_info = gm->map_info;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		open_error();
	line = get_next_line(fd);
	if (!line)
		map_error(NO_MAP, fd, gm);
	map_info->width = ft_strlen(line) - 1;
	line[map_info->width] = '\0';
	while (line)
		map_parser_sub(fd, &line, gm);
	is_map(gm, fd);
}
