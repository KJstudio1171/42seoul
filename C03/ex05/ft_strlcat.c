/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:50:17 by junekim           #+#    #+#             */
/*   Updated: 2021/09/21 13:21:13 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	j;

	dest_len = 0;
	src_len = 0;
	j = 0;
	while (dest[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	while (src[j] && j + dest_len + 1 < size)
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	if (dest_len < size)
	{
		dest[j + dest_len] = '\0';
		return (dest_len + src_len);
	}
	return (src_len + size);
}
