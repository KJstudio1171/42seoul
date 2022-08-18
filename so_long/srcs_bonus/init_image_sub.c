/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:02:40 by junekim           #+#    #+#             */
/*   Updated: 2022/08/17 23:09:57 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images_sub6(t_game_manager *gm, t_images *im)
{
	im -> fighter[8] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_r2.xpm", &(im -> width), &(im -> height));
	im -> fighter[9] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_f0.xpm", &(im -> width), &(im -> height));
	im -> fighter[10] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_f1.xpm", &(im -> width), &(im -> height));
	im -> fighter[11] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_f2.xpm", &(im -> width), &(im -> height));
	im -> black_64 = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/black_64.xpm", &(im -> width), &(im -> height));
	im -> black_96 = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/black_96.xpm", &(im -> width), &(im -> height));
	im -> missile_fighter[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile1f.xpm", &(im -> width), &(im -> height));
	im -> missile_enemy[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile0l.xpm", &(im -> width), &(im -> height));
	im -> missile_enemy[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile0b.xpm", &(im -> width), &(im -> height));
	im -> missile_enemy[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile0r.xpm", &(im -> width), &(im -> height));
	im -> missile_enemy[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile0f.xpm", &(im -> width), &(im -> height));
}

void	init_images_sub5(t_game_manager *gm, t_images *im)
{
	im -> enemy[8] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_b2.xpm", &(im -> width), &(im -> height));
	im -> enemy[9] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_l0.xpm", &(im -> width), &(im -> height));
	im -> enemy[10] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_l1.xpm", &(im -> width), &(im -> height));
	im -> enemy[11] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_l2.xpm", &(im -> width), &(im -> height));
	im -> fighter[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_l0.xpm", &(im -> width), &(im -> height));
	im -> fighter[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_l1.xpm", &(im -> width), &(im -> height));
	im -> fighter[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_l2.xpm", &(im -> width), &(im -> height));
	im -> fighter[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_b0.xpm", &(im -> width), &(im -> height));
	im -> fighter[4] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_b1.xpm", &(im -> width), &(im -> height));
	im -> fighter[5] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_b2.xpm", &(im -> width), &(im -> height));
	im -> fighter[6] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_r0.xpm", &(im -> width), &(im -> height));
	im -> fighter[7] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_r1.xpm", &(im -> width), &(im -> height));
	init_images_sub6(gm, im);
}
