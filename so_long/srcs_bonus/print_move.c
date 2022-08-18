/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:39:44 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:53:36 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_number(t_game_manager *gm, char *ptr)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(ptr);
	while (i <= len)
	{
		if (gm -> screen_width - 64 * (i + 1) >= 0)
		{
			mlx_put_image_to_window(gm->mlx, gm->win, gm->images->black_64, \
			gm -> screen_width - 64 * (i + 1), gm->screen_height - 64);
			mlx_put_image_to_window(gm->mlx, gm->win, gm->images-> \
			number[ptr[len - i] - '0'], gm -> screen_width - 64 * \
			(i + 1), gm->screen_height - 64);
		}
		i++;
	}
}

void	print_move(t_game_manager *gm)
{
	char	*ptr;

	gm->move_num++;
	ptr = ft_itoa(gm->move_num);
	print_number(gm, ptr);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	mlx_put_image_to_window(gm->mlx, gm->win, \
	gm->images->black_64, 0, gm->screen_height - 64);
	mlx_string_put(gm->mlx, gm->win, 0, gm->screen_height - 32, 0x00000FF, ptr);
	free(ptr);
}
