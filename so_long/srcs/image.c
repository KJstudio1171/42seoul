/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:56:22 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 11:07:05 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_48(t_game_manager *gm, void *image, int width, int height)
{
	mlx_put_image_to_window(gm->mlx, gm->win, image, width * 48, height * 48);
}
