/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:23:06 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 15:23:11 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct t_map
{
	char	**map;
	int		**int_map;

	int		column_size;
	int		row_size;
	char	road;
	char	obs;
	char	square;
}	t_map;
#endif