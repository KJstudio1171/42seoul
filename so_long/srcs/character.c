/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:18:53 by junekim           #+#    #+#             */
/*   Updated: 2022/08/15 06:12:12 by junekim          ###   ########seoul.kr  */
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

static void	print_move(t_game_manager *gm)
{
	char	*ptr;

	gm->move_num++;
	ptr = ft_itoa(gm->move_num);
	write(1, ptr, ft_strlen(ptr));
	write(1, "\n", 1);
	free(ptr);
}

static void	move_sub(char *old_position, char *new_position, t_game_manager *gm)
{
	if (*new_position == '1')
		return ;
	else if (*new_position == '0' || *new_position == 'C')
	{
		old_position_change(old_position);
		*new_position = 'P';
		print_move(gm);
	}
	else if (*new_position == 'E')
	{
		old_position_change(old_position);
		*new_position = 'Q';
		print_move(gm);
		finish(gm);
	}
}

int	move(int dir, t_game_manager *gm)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = gm -> map_info -> map_string;
	if (dir == ESC)
		close_game(gm);
	while (ptr[i] != 'P' && ptr[i] != 'Q')
		i++;
	if (dir == W)
		move_sub(&ptr[i], &ptr[i - gm -> map_info ->width], gm);
	else if (dir == A)
		move_sub(&ptr[i], &ptr[i - 1], gm);
	else if (dir == D)
		move_sub(&ptr[i], &ptr[i + 1], gm);
	else if (dir == S)
		move_sub(&ptr[i], &ptr[i + gm -> map_info ->width], gm);
	map_update(gm);
	return (1);
}
