/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 20:10:28 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 18:43:13 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_strlen_arrary(int size, char **strs)
{
	int		*strlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strlen = (int *)malloc(sizeof(int) * (size + 1));
	strlen[size] = 0;
	while (i < size)
	{
		strlen[i] = 0;
		while (strs[i][j])
		{
			strlen[i]++;
			strlen[size]++;
			j++;
		}
		i++;
		j = 0;
	}
	return (strlen);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*tmp;

	tmp = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (tmp);
}

char	*size_0(void)
{
	return ((char *)malloc(sizeof(char)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		*strlen;
	int		seplen;
	int		i;
	char	*strjoin;

	seplen = 0;
	i = 0;
	if (size <= 0)
		return (size_0());
	while (sep[seplen])
		seplen++;
	strlen = ft_strlen_arrary(size, strs);
	strjoin = (char *)malloc(1 * strlen[size] + (size - 1) * seplen + 1);
	if (!strjoin || !strlen)
		return (0);
	strjoin[0] = '\0';
	while (i < size)
	{
		ft_strcat(strjoin, &strs[i][0]);
		if (i < size - 1)
			ft_strcat(strjoin, sep);
		i++;
	}
	return (strjoin);
}
