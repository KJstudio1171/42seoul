/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:01:40 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 16:03:47 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mlx_destroy(t_game_manager *gm)
{
	mlx_destroy_window(gm->mlx, gm->win);
}

void	finish(t_game_manager *gm)
{
	if (gm -> map_info -> collectible == 0)
	{
		gm->time_64 = gm->time;
		gm->chest_open = 0;
		gm->enemy_destroy = 0;
		gm->finish = 1;
	}
}

int	close_game(t_game_manager *gm)
{
	ft_mlx_destroy(gm);
	if (gm->map_info->map_string)
		free(gm->map_info->map_string);
	if (gm->animation->flag)
		free(gm->animation->flag);
	if (gm->animation->enemy)
		free(gm->animation->enemy);
	if (gm->animation->missile_enemy)
		free(gm->animation->missile_enemy);
	if (gm->animation->missile_fighter)
		free(gm->animation->missile_fighter);
	exit(0);
	return (1);
}
