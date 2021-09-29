/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:19:58 by junekim           #+#    #+#             */
/*   Updated: 2021/09/29 15:58:05 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "find_square.h"

void	info_error(void)
{
	write(1, "info_error", 10);
	exit(1);
}

void	file_open_error(void)
{
	write(1, "file_open_error", 15);
	exit(1);
}

void	file_read_error(void)
{
	write(1, "file_read_error", 15);
	exit(1);
}

void	malloc_error(void)
{
	write(1, "malloc_error", 12);
	exit(1);
}

void	overflow_error(void)
{	
	write(1, "overflow_error", 14);
	exit(1);
}

void	map_error(void)
{	
	write(1, "map_error", 9);
	exit(1);
}