/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:51:12 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:53:17 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_animation_sub(t_game_manager *gm, \
char *ptr, size_t w, size_t h)
{
	int		random;

	if (*ptr == 'E')
	{
		gm -> animation -> flag[gm -> animation -> exit].exist = 1;
		gm -> animation -> flag[gm -> animation -> exit].width = w;
		gm -> animation -> flag[gm -> animation -> exit].height = h;
		gm -> animation -> exit += 1;
	}
	else if (*ptr == 'e')
	{
		random = rand() % 4;
		ft_putnbr_fd(random, 1);
		write(1, "\n", 1);
		gm -> animation -> enemy[gm->animation->enemy_num].exist = 1;
		gm -> animation -> enemy[gm->animation->enemy_num].dir = random;
		gm -> animation -> enemy[gm->animation->enemy_num].width = w;
		gm -> animation -> enemy[gm->animation->enemy_num].height = h;
		gm -> animation -> enemy[gm->animation->enemy_num].ptr = ptr;
		gm->animation->missile_enemy[gm->animation->enemy_num].exist = 0;
		gm->animation->missile_enemy[gm->animation->enemy_num].dir = random;
		gm -> animation -> enemy_num += 1;
	}
}

static void	animation_allocation(t_game_manager *gm)
{
	gm -> animation -> flag = \
	(t_position *)malloc(sizeof(t_position) * (gm -> map_info -> exit));
	gm -> animation -> enemy = \
	(t_position *)malloc(sizeof(t_position) * (gm -> map_info -> enemy));
	gm -> animation -> missile_enemy = \
	(t_position *)malloc(sizeof(t_position) * (gm -> map_info -> enemy));
	gm -> animation -> missile_fighter = \
	(t_position *)malloc(sizeof(t_position));
}

void	init_animation(t_game_manager *gm)
{
	char	*ptr;
	size_t	width;
	size_t	height;

	width = 0;
	height = 0;
	ptr = gm->map_info -> map_string;
	gm -> animation -> exit = 0;
	gm -> animation -> enemy_num = 0;
	animation_allocation(gm);
	gm -> animation -> missile_fighter -> exist = 0;
	gm -> animation -> missile_fighter -> type = 0;
	srand(time(NULL));
	while (*ptr && height < gm->map_info->height)
	{
		while (width < gm->map_info->width)
		{
			init_animation_sub(gm, ptr, width, height);
			width++;
			ptr++;
		}
		width = 0;
		height++;
	}
}
