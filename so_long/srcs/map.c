/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:41 by junekim           #+#    #+#             */
/*   Updated: 2022/08/14 23:15:17 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_update_sub(t_game_manager *gm, char *ptr, size_t w, size_t h)
{
	image_48(gm, gm->images->grass, w, h);
	if (*ptr == '0')
		image_48(gm, gm->images->grass, w, h);
	else if (*ptr == '1')
	{
		image_48(gm, gm->images->fence, w, h);
	}
	else if (*ptr == 'C')
	{
		gm -> map_info -> collectible += 1;
		image_48(gm, gm->images->chest0, w, h);
	}
	else if (*ptr == 'E')
		image_48(gm, gm->images->cow0, w, h);
	else if (*ptr == 'P')
		image_48(gm, gm->images->cf0, w, h);
	else if (*ptr == 'Q')
	{
		image_48(gm, gm->images->cow0, w, h);
		image_48(gm, gm->images->cf0, w, h);
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
