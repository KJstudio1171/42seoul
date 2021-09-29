/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:38:26 by junekim           #+#    #+#             */
/*   Updated: 2021/09/28 16:19:38 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H
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