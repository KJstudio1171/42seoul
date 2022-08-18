/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_image_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:23:12 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:24:18 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_64(t_game_manager *gm, void **image, int w, int h)
{
	int	time;

	time = (gm->time - gm->time_64) % SPEED;
	if (time < SPEED / 4)
	{
		mi(gm, gm->images->enemy_64[0], w, h);
		mi(gm, gm->images->enemy_64[1], w, h);
		mi(gm, image[0], w, h);
	}
	else if (time < SPEED / 4 * 2)
	{
		mi(gm, gm->images->enemy_64[0], w, h);
		mi(gm, gm->images->enemy_64[1], w, h);
		mi(gm, image[1], w, h);
	}
	else if (time < SPEED / 4 * 3)
	{
		mi(gm, image[2], w, h);
	}
	else if (time < SPEED)
	{
		mi(gm, gm->images->black_96, w, h);
		gm->chest_open = 0;
		gm->enemy_destroy = 0;
	}
}

static void	finish_64(t_game_manager *gm, void **image, int w, int h)
{
	int	time;

	time = (gm->time - gm->time_64) % SPEED;
	if (time < SPEED / 5)
	{
		mi(gm, image[0], w, h);
	}
	else if (time < SPEED / 5 * 2)
	{
		mi(gm, image[1], w, h);
	}
	else if (time < SPEED / 5 * 3)
	{
		mi(gm, image[2], w, h);
	}
	else if (time < SPEED / 5 * 4)
	{
		mi(gm, image[3], w, h);
	}
	else if (time < SPEED)
	{
		close_game(gm);
		mi(gm, gm->images->black_96, w, h);
	}
}

static void	chest_64(t_game_manager *gm, void **image, int w, int h)
{
	int	time;

	time = (gm->time - gm->time_64) % SPEED;
	if (time < SPEED / 4)
	{
		mi(gm, image[0], w, h);
	}
	else if (time < SPEED / 4 * 2)
	{
		mi(gm, image[1], w, h);
	}
	else if (time < SPEED / 4 * 3)
	{
		mi(gm, image[2], w, h);
	}
	else if (time < SPEED)
	{
		mi(gm, gm->images->black_96, w, h);
		gm->chest_open = 0;
		gm->enemy_destroy = 0;
	}
}

void	animate_image_64(t_game_manager *gm, void **image)
{
	int	w;
	int	h;

	w = gm->screen_width - 64;
	h = gm->screen_height - 64;
	mi(gm, gm->images->black_64, w, h);
	if (gm->finish)
		finish_64(gm, image, w, h);
	else if (gm->enemy_destroy)
		enemy_64(gm, image, w, h);
	else if (gm->chest_open)
		chest_64(gm, image, w, h);
}
