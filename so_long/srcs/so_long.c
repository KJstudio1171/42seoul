/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:23:24 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 06:56:57 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_images		images;
	t_map_info		map_info;
	t_game_manager	gm;

	if (argc != 2)
		file_error();
	init(&gm, &map_info, &images, argv[1]);
	map_update(&gm);
	mlx_hook(gm.win, KEY_PRESS, 0, move, &gm);
	mlx_hook(gm.win, EXIT, 0, close_game, &gm);
	mlx_loop(gm.mlx);
}
