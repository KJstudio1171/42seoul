/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:01:40 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 15:51:32 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_mlx_destroy(t_game_manager *gm)
{
	mlx_destroy_image(gm->mlx, gm->images->cf0);
	mlx_destroy_image(gm->mlx, gm->images->chest0);
	mlx_destroy_image(gm->mlx, gm->images->cow0);
	mlx_destroy_image(gm->mlx, gm->images->fence);
	mlx_destroy_image(gm->mlx, gm->images->grass);
	mlx_destroy_window(gm->mlx, gm->win);
}

void	finish(t_game_manager *gm)
{
	if (gm -> map_info -> collectible == 0)
		close_game(gm);
}

int	close_game(t_game_manager *gm)
{
	if (gm->map_info->map_string)
		free(gm->map_info->map_string);
	ft_mlx_destroy(gm);
	exit(0);
	return (1);
}
