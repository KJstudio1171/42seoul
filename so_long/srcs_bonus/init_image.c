/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 06:01:37 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 12:14:40 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_images_sub4(t_game_manager *gm, t_images *im)
{
	im -> number[9] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/9.xpm", &(im -> width), &(im -> height));
	im -> enemy[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_f0.xpm", &(im -> width), &(im -> height));
	im -> enemy[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_f1.xpm", &(im -> width), &(im -> height));
	im -> enemy[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_f2.xpm", &(im -> width), &(im -> height));
	im -> enemy[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_r0.xpm", &(im -> width), &(im -> height));
	im -> enemy[4] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_r1.xpm", &(im -> width), &(im -> height));
	im -> enemy[5] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_r2.xpm", &(im -> width), &(im -> height));
	im -> enemy[6] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_b0.xpm", &(im -> width), &(im -> height));
	im -> enemy[7] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_b1.xpm", &(im -> width), &(im -> height));
	im -> missile_fighter[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile1l.xpm", &(im -> width), &(im -> height));
	im -> missile_fighter[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile1b.xpm", &(im -> width), &(im -> height));
	im -> missile_fighter[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/missile1r.xpm", &(im -> width), &(im -> height));
}

static void	init_images_sub3(t_game_manager *gm, t_images *im)
{
	im -> alphabet[5] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/d.xpm", &(im -> width), &(im -> height));
	im -> alphabet[6] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/i.xpm", &(im -> width), &(im -> height));
	im -> alphabet[7] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/o.xpm", &(im -> width), &(im -> height));
	im -> number[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/0.xpm", &(im -> width), &(im -> height));
	im -> number[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/1.xpm", &(im -> width), &(im -> height));
	im -> number[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/2.xpm", &(im -> width), &(im -> height));
	im -> number[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/3.xpm", &(im -> width), &(im -> height));
	im -> number[4] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/4.xpm", &(im -> width), &(im -> height));
	im -> number[5] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/5.xpm", &(im -> width), &(im -> height));
	im -> number[6] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/6.xpm", &(im -> width), &(im -> height));
	im -> number[7] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/7.xpm", &(im -> width), &(im -> height));
	im -> number[8] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/8.xpm", &(im -> width), &(im -> height));
}

static void	init_images_sub2(t_game_manager *gm, t_images *im)
{
	im -> fighter_96[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_96_0.xpm", &(im -> width), &(im -> height));
	im -> fighter_96[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_96_1.xpm", &(im -> width), &(im -> height));
	im -> fighter_96[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/fighter_96_2.xpm", &(im -> width), &(im -> height));
	im -> alphabet_64[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/w_64.xpm", &(im -> width), &(im -> height));
	im -> alphabet_64[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/i_64.xpm", &(im -> width), &(im -> height));
	im -> alphabet_64[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/n.xpm", &(im -> width), &(im -> height));
	im -> alphabet_64[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/!.xpm", &(im -> width), &(im -> height));
	im -> alphabet[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/K.xpm", &(im -> width), &(im -> height));
	im -> alphabet[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/J.xpm", &(im -> width), &(im -> height));
	im -> alphabet[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/s.xpm", &(im -> width), &(im -> height));
	im -> alphabet[3] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/t.xpm", &(im -> width), &(im -> height));
	im -> alphabet[4] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/u.xpm", &(im -> width), &(im -> height));
}

void	init_images_sub1(t_game_manager *gm, t_images *im)
{
	im -> chest_64[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/chest0_64.xpm", &(im -> width), &(im -> height));
	im -> chest_64[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/chest1_64.xpm", &(im -> width), &(im -> height));
	im -> chest_64[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/chest2_64.xpm", &(im -> width), &(im -> height));
	im -> flag[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/flag0.xpm", &(im -> width), &(im -> height));
	im -> flag[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/flag1.xpm", &(im -> width), &(im -> height));
	im -> flag[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/flag2.xpm", &(im -> width), &(im -> height));
	im -> explosion_64[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/explosion0_64.xpm", &(im -> width), &(im -> height));
	im -> explosion_64[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/explosion1_64.xpm", &(im -> width), &(im -> height));
	im -> explosion_64[2] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/explosion2_64.xpm", &(im -> width), &(im -> height));
}

void	init_images(t_game_manager *gm, t_images *im)
{
	im -> height = 0;
	im -> width = 0;
	im -> chest = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/chest.xpm", &(im -> width), &(im -> height));
	im -> enemy_body = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy_body.xpm", &(im -> width), &(im -> height));
	im -> grass = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/grass.xpm", &(im -> width), &(im -> height));
	im -> house = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/house.xpm", &(im -> width), &(im -> height));
	im -> topgun = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/topgun.xpm", &(im -> width), &(im -> height));
	im -> enemy_64[0] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy0_64.xpm", &(im -> width), &(im -> height));
	im -> enemy_64[1] = mlx_xpm_file_to_image(gm -> mlx, \
	"./sprites_bonus/enemy1_64.xpm", &(im -> width), &(im -> height));
	init_images_sub1(gm, im);
	init_images_sub2(gm, im);
	init_images_sub3(gm, im);
	init_images_sub4(gm, im);
	init_images_sub5(gm, im);
}
