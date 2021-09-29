/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:57:23 by junekim           #+#    #+#             */
/*   Updated: 2021/09/28 20:22:31 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_info_error(void)
{
	write(1, "info_error", 10);
	exit(1);
}

void	ft_file_open_error(void)
{
	write(1, "file_open_error", 15);
	exit(1);
}

void	ft_file_read_error(void)
{
	write(1, "file_read_error", 15);
	exit(1);
}

void	ft_malloc_error(void)
{
	write(1, "malloc_error", 12);
	exit(1);
}

void	ft_overflow(void)
{	
	write(1, "overflow_error", 14);
	exit(1);
}

void	ft_map_error(void)
{	
	write(1, "map_error", 9);
	exit(1);
}