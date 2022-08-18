/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 07:42:59 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:59:21 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animation_update_32_sub3(t_game_manager *gm)
{
	image_32(gm, gm->images->missile_fighter[gm-> \
	animation->missile_fighter->dir % 10], gm->animation \
	->missile_fighter->width, gm->animation->missile_fighter->height);
	if (gm->time - gm->animation->missile_fighter->time > SPEED / 10)
	{
		gm->animation->missile_fighter->time = gm->time;
		map_update(gm);
		missile_move(gm, gm->animation->missile_fighter);
	}
}

static void	animation_update_32_sub2(t_game_manager *gm)
{
	if (gm->finish)
	{
		animate_image_64(gm, gm->images->alphabet_64);
	}
	if (gm->enemy_destroy)
	{
		animate_image_64(gm, gm->images->explosion_64);
	}
	else if (gm->chest_open)
	{
		animate_image_64(gm, gm->images->chest_64);
	}
}

static void	animation_update_32_sub1(t_game_manager *gm, int i)
{
	image_32(gm, gm -> images -> grass, \
	gm->animation->enemy[i].width, gm->animation->enemy[i].height);
	image_32(gm, gm -> images -> enemy_body, \
	gm->animation->enemy[i].width, gm->animation->enemy[i].height);
	animate_image_32(gm, &(gm -> \
	images -> enemy[gm-> animation->enemy[i].dir * 3]), \
	gm->animation->enemy[i].width, gm->animation->enemy[i].height);
}

static void	animation_update_32(t_game_manager *gm)
{
	int	i;

	i = 0;
	while (i < gm -> animation -> exit)
	{
		if (gm->animation->flag[i].exist)
			animate_image_32(gm, gm -> images -> flag, \
			gm->animation->flag[i].width, gm->animation->flag[i].height);
		i++;
	}
	animate_image_32_2(gm, &(gm -> images -> fighter[3 * ((gm -> dir) % 10)]), \
	gm -> x, gm -> y);
	i = 0;
	while (i < gm -> animation -> enemy_num)
	{
		if (*(gm->animation->enemy[i].ptr) == 'e')
			animation_update_32_sub1(gm, i);
		i++;
	}
	if (gm->animation->missile_fighter->exist)
		animation_update_32_sub3(gm);
	animation_update_32_sub2(gm);
}

int	frame_update(t_game_manager *gm)
{
	gm -> time = gm->time + 1;
	if (gm -> topgun)
		animate_image_96(gm, gm->images->fighter_96, gm->x);
	else
		animation_update_32(gm);
	return (1);
}
