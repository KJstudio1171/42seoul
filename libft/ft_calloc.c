/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:19:18 by junekim           #+#    #+#             */
/*   Updated: 2021/12/30 11:25:45 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	ft_bzero(ptr, n * size);
	return (ptr);
}
