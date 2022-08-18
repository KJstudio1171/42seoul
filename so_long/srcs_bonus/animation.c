/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:39:27 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:24:06 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_image_32_2(t_game_manager *gm, void **image, int w, int h)
{
	int	time;

	time = gm->time % SPEED;
	if (time < SPEED / 4)
	{
		image_32(gm, gm -> images -> grass, w, h);
		image_32(gm, image[0], w, h);
	}
	else if (time < SPEED / 4 * 2)
	{
		image_32(gm, gm -> images -> grass, w, h);
		image_32(gm, image[1], w, h);
	}
	else if (time < SPEED / 4 * 3)
	{
		image_32(gm, gm -> images -> grass, w, h);
		image_32(gm, image[2], w, h);
	}
	else if (time < SPEED)
	{
		image_32(gm, gm -> images -> grass, w, h);
		image_32(gm, image[1], w, h);
	}
}

void	animate_image_32(t_game_manager *gm, void **image, int w, int h)
{
	int	time;

	time = gm->time % SPEED;
	if (time < SPEED / 4)
		image_32(gm, image[0], w, h);
	else if (time < SPEED / 4 * 2)
		image_32(gm, image[1], w, h);
	else if (time < SPEED / 4 * 3)
		image_32(gm, image[2], w, h);
	else if (time < SPEED)
		image_32(gm, image[1], w, h);
}

void	animate_image_96(t_game_manager *gm, void **image, int w)
{
	int	time;

	time = gm->time % SPEED;
	if (time < SPEED / 4)
	{
		image_96(gm, gm -> images -> black_96, w);
		image_96(gm, image[0], w);
	}
	else if (time < SPEED / 4 * 2)
	{
		image_96(gm, gm -> images -> black_96, w);
		image_96(gm, image[1], w);
	}
	else if (time < SPEED / 4 * 3)
	{
		image_96(gm, gm -> images -> black_96, w);
		image_96(gm, image[2], w);
	}
	else if (time < SPEED)
	{
		image_96(gm, gm -> images -> black_96, w);
		image_96(gm, image[1], w);
	}
}
