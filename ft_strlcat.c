/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 01:46:11 by junekim           #+#    #+#             */
/*   Updated: 2021/09/19 02:14:41 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len = 0;
	int	src_len = 0;
	int	j = 0;

	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	while ( src[j] && j + dest_len + 1 < size)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	if (dest_len<size)
	{
		dest[j+dest_len] = '\0';
		return dest_len + src_len;
	}
	return src_len + size;
}
