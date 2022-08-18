/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:56:22 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 12:52:22 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mi(t_game_manager *gm, void *image, int width, int height)
{
	mlx_put_image_to_window(gm->mlx, gm->win, image, width, height);
}

void	image_32(t_game_manager *gm, void *image, int width, int height)
{
	mlx_put_image_to_window(gm->mlx, gm->win, image, width * 32, height * 32);
}

void	image_96(t_game_manager *gm, void *image, int width)
{
	mlx_put_image_to_window(gm->mlx, gm->win, image, width * 96, 320);
}
