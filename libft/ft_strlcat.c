/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:50:17 by junekim           #+#    #+#             */
/*   Updated: 2021/12/28 07:26:44 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	j;

	dest_len = 0;
	src_len = 0;
	j = 0;
	while (dst[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	while (src[j] && j + dest_len + 1 < size)
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	if (dest_len < size)
	{
		dst[j + dest_len] = '\0';
		return (dest_len + src_len);
	}
	return (src_len + size);
}
