/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:18:53 by junekim           #+#    #+#             */
/*   Updated: 2022/08/18 13:40:25 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	old_position_change(char *old_position)
{
	if (*old_position == 'Q')
		*old_position = 'E';
	else if (*old_position == 'P')
		*old_position = '0';
}

static void	move_sub3(int dir, t_game_manager *gm)
{
	if (dir == SPACE)
		missile(gm);
	if (dir == ESC)
		close_game(gm);
}

static void	move_sub2(char *op, char *np, t_game_manager *gm)
{
	gm->chest_open = 1;
	if (!(gm->enemy_destroy))
		gm->time_64 = gm->time;
	old_position_change(op);
	*np = 'P';
	print_move(gm);
}

static void	move_sub(char *old_position, char *new_position, t_game_manager *gm)
{
	if (*new_position == '1')
		return ;
	else if (*new_position == '0')
	{
		old_position_change(old_position);
		*new_position = 'P';
		print_move(gm);
	}
	else if (*new_position == 'C')
		move_sub2(old_position, new_position, gm);
	else if (*new_position == 'E')
	{
		old_position_change(old_position);
		*new_position = 'Q';
		print_move(gm);
		finish(gm);
	}
	else if (*new_position == 'e')
	{
		old_position_change(old_position);
		print_move(gm);
		close_game(gm);
	}
}

int	move(int dir, t_game_manager *gm)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = gm -> map_info -> map_string;
	frame_update(gm);
	if (dir == SPACE || dir == ESC)
	{
		move_sub3(dir, gm);
		return (1);
	}
	while (ptr[i] != 'P' && ptr[i] != 'Q')
		i++;
	if (dir == W && gm -> dir == W)
		move_sub(&ptr[i], &ptr[i - gm -> map_info ->width], gm);
	else if (dir == A && gm -> dir == A)
		move_sub(&ptr[i], &ptr[i - 1], gm);
	else if (dir == D && gm -> dir == D)
		move_sub(&ptr[i], &ptr[i + 1], gm);
	else if (dir == S && gm -> dir == S)
		move_sub(&ptr[i], &ptr[i + gm -> map_info ->width], gm);
	gm -> dir = dir;
	map_update(gm);
	return (1);
}
