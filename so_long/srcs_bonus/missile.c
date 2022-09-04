/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:06:16 by junekim           #+#    #+#             */
/*   Updated: 2022/08/19 18:04:35 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	missile(t_game_manager *gm)
{
	if (gm -> animation -> missile_fighter -> exist)
		return ;
	gm->animation->missile_fighter->time = gm->time;
	gm -> animation -> missile_fighter -> exist = 1;
	gm -> animation -> missile_fighter -> width = gm -> x;
	gm -> animation -> missile_fighter -> height = gm -> y;
	gm -> animation -> missile_fighter -> dir = gm -> dir;
}

static void	missile_move_sub1(char *np, t_game_manager *gm, \
t_position *position)
{
	if (*np == '1')
	{
		position->exist = 0;
	}
	else if (*np == 'e')
	{
		if (!(position->type))
		{
			position->exist = 0;
			*np = '0';
			gm->enemy_destroy = 1;
			gm->time_64 = gm->time;
			map_update(gm);
		}
	}
	else if (*np == 'c')
	{
		map_update(gm);
	}
}

static void	missile_move_sub2(t_game_manager *gm, t_position *position)
{
	int		i;
	int		dir;
	char	*ptr;

	i = position->height * gm->map_info->width + position->width;
	dir = position -> dir;
	ptr = gm -> map_info -> map_string;
	if (dir == S)
	{
		missile_move_sub1(&ptr[i + gm->map_info->width], gm, position);
		position->height += 1;
	}
	else if (dir == D)
	{
		missile_move_sub1(&ptr[i + 1], gm, position);
		position->width += 1;
	}
}

void	missile_move(t_game_manager *gm, t_position *position)
{
	int		i;
	int		dir;
	char	*ptr;

	i = position->height * gm->map_info->width + position->width;
	dir = position -> dir;
	ptr = gm -> map_info -> map_string;
	if (dir == W)
	{
		missile_move_sub1(&ptr[i - gm->map_info->width], gm, position);
		position->height += -1;
	}
	else if (dir == A)
	{
		missile_move_sub1(&ptr[i - 1], gm, position);
		position->width += -1;
	}
	else
		missile_move_sub2(gm, position);
}
