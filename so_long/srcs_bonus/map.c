/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:41 by junekim           #+#    #+#             */
/*   Updated: 2022/08/17 22:13:43 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_update_sub(t_game_manager *gm, char *ptr, size_t w, size_t h)
{
	if (*ptr == '0')
		image_32(gm, gm->images->grass, w, h);
	else if (*ptr == '1')
	{
		image_32(gm, gm->images->house, w, h);
	}
	else if (*ptr == 'C')
	{
		gm -> map_info -> collectible += 1;
		image_32(gm, gm->images->grass, w, h);
		image_32(gm, gm->images->chest, w, h);
	}
	else if (*ptr == 'P')
	{
		gm -> x = w;
		gm -> y = h;
	}
	else if (*ptr == 'Q')
	{
		gm -> x = w;
		gm -> y = h;
	}
}

void	map_update(t_game_manager *gm)
{
	char	*ptr;
	size_t	width;
	size_t	height;

	width = 0;
	height = 0;
	ptr = gm->map_info -> map_string;
	gm -> map_info -> collectible = 0;
	while (*ptr && height < gm->map_info->height)
	{
		while (width < gm->map_info->width)
		{
			map_update_sub(gm, ptr, width, height);
			width++;
			ptr++;
		}
		width = 0;
		height++;
	}
}
