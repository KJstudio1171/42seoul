/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:47:14 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 10:36:53 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images(t_game_manager *gm, t_images *images)
{
	images -> height = 0;
	images -> width = 0;
	images -> grass = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites/grass.xpm", &(images -> width), &(images -> height));
	images -> fence = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites/fence.xpm", &(images -> width), &(images -> height));
	images -> cow0 = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites/cow0.xpm", &(images -> width), &(images -> height));
	images -> cf0 = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites/cf0.xpm", &(images -> width), &(images -> height));
	images -> chest0 = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites/chest0.xpm", &(images -> width), &(images -> height));
}

static void	init_map_info(t_map_info *map_info)
{
	map_info -> height = 0;
	map_info -> width = 0;
	map_info -> collectible = 0;
	map_info -> start_position = 0;
	map_info -> exit = 0;
	map_info -> map_string = (char *)malloc(sizeof(char));
}

static void	init_game_manager(t_game_manager *gm)
{
	gm -> clear = 0;
	gm -> move_num = 0;
	gm -> mlx = mlx_init();
	gm -> win = mlx_new_window(gm -> mlx, gm->map_info->width * 48, \
	gm->map_info->height * 48, "so_long");
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
}
