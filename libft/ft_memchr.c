/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:10:56 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:03:37 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *ptr, int value, size_t num)
{
	while (num--)
	{
		if (*((unsigned char *)ptr) == (unsigned char)value)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
