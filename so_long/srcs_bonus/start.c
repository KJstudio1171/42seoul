/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:10:32 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:42:51 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_page(t_game_manager *gm)
{
	mlx_put_image_to_window(gm->mlx, gm->win, gm -> images->topgun, 0, 0);
	mlx_hook(gm -> win, KEY_PRESS, 0, move_start, gm);
	mlx_hook(gm -> win, EXIT, 0, close_game, gm);
}

static int	move_start_sub(t_game_manager *gm)
{
	if (gm->map_info->width > 4)
	{
		gm -> win = mlx_new_window(gm -> mlx, gm->map_info->width * 32, \
		gm->map_info->height * 32 + 64, "mlx 42");
		gm->screen_width = gm->map_info->width * 32;
		gm->screen_height = gm->map_info->height * 32 + 64;
	}
	else
	{
		gm -> win = mlx_new_window(gm -> mlx, 128, \
		gm->map_info->height * 32 + 64, "mlx 42");
		gm->screen_width = 128;
		gm->screen_height = gm->map_info->height * 32 + 64;
	}
}

int	move_start(int dir, t_game_manager *gm)
{
	animate_image_96(gm, gm->images->fighter_96, gm->x);
	if (dir == D)
	{
		image_96(gm, gm -> images -> black_96, gm -> x);
		if (gm -> x > 0 && gm -> x < 9)
			image_96(gm, gm -> images -> alphabet[gm -> x - 1], gm -> x);
		gm->move_num++;
		gm->x++;
	}
	if (gm->move_num > 10)
	{
		gm->topgun = 0;
		gm->move_num = 0;
		mlx_destroy_window(gm->mlx, gm->win);
		move_start_sub(gm);
		mlx_hook(gm->win, KEY_PRESS, 0, move, gm);
		mlx_hook(gm->win, EXIT, 0, close_game, gm);
		map_update(gm);
	}
	return (1);
}
