/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:47:14 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:51:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_info(t_map_info *map_info)
{
	map_info -> height = 0;
	map_info -> width = 0;
	map_info -> collectible = 0;
	map_info -> start_position = 0;
	map_info -> enemy = 0;
	map_info -> exit = 0;
	map_info -> map_string = (char *)malloc(sizeof(char));
}

static void	init_game_manager(t_game_manager *gm)
{
	gm -> clear = 0;
	gm -> move_num = 0;
	gm -> x = 0;
	gm -> y = 1;
	gm -> dir = 0;
	gm -> topgun = 1;
	gm -> time = 0;
	gm->time_64 = 0;
	gm->chest_open = 0;
	gm->enemy_destroy = 0;
	gm->finish = 0;
	gm -> mlx = mlx_init();
	gm -> win = mlx_new_window(gm -> mlx, 960, 416, "top gun");
}

void	init(t_game_manager *gm, t_map_info *mi, t_images *im, char *fn)
{
	if (ft_strlen(fn) < 4)
		file_error();
	if (ft_strncmp(&(fn[ft_strlen(fn) - 1 - 3]), ".ber", 4))
		file_error();
	gm -> map_info = mi;
	gm -> images = im;
	init_map_info(mi);
	map_parser(gm, fn);
	init_game_manager(gm);
	init_images(gm, im);
	init_animation(gm);
}
