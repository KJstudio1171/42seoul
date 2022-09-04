/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:07:19 by junekim           #+#    #+#             */
/*   Updated: 2022/08/19 18:37:31 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("check the number of arguments or file name\n", 1);
	exit(1);
}

void	open_error(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd("open function is not working\n", 1);
	exit(1);
}

void	error_manager(t_game_manager *gm)
{
	if (gm->map_info->map_string)
		free(gm->map_info->map_string);
	exit(1);
}

void	map_error(int flag, int fd, t_game_manager *gm)
{
	close(fd);
	ft_putstr_fd("Error\n", 1);
	if (flag == NO_MAP)
		ft_putstr_fd("no map or not working GNL\n", 1);
	else if (flag == NO_WALL)
		ft_putstr_fd("not closed/surrounded by walls\n", 1);
	else if (flag == NO_EXIT)
		ft_putstr_fd("no exit\n", 1);
	else if (flag == NO_COLLECTIBLE)
		ft_putstr_fd("no collectible\n", 1);
	else if (flag == NO_START_POSITION)
		ft_putstr_fd("not one start position\n", 1);
	else if (flag == NO_RECTANGULAR)
		ft_putstr_fd("not rectangular\n", 1);
	error_manager(gm);
}
