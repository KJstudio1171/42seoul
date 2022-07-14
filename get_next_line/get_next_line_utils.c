/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:28:40 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 00:54:08 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	while (i < len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	j = 0;
	while (src[j] && j + dest_len + 1 < size)
	{
		dst[dest_len + j] = src[j];
		j++;
	}
	if (dest_len + 1 <= size)
	{
		dst[j + dest_len] = '\0';
		return (dest_len + src_len);
	}
	dest_len = size;
	return (src_len + dest_len);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	chr;

	if (!str)
		return (NULL);
	i = 0;
	chr = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == chr)
		return ((char *)&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!(result))
		return (NULL);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
