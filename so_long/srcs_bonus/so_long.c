/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:23:24 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 11:05:27 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_images		images;
	t_map_info		map_info;
	t_animation		animation;
	t_game_manager	gm;

	if (argc != 2)
		file_error();
	gm.animation = &animation;
	init(&gm, &map_info, &images, argv[1]);
	start_page(&gm);
	mlx_loop_hook(gm.mlx, frame_update, &gm);
	mlx_loop(gm.mlx);
}
