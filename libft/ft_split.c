/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:50:58 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:07:23 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	split_size_function(char *s, char c)
{
	int		split_size;
	int		i;

	split_size = 0;
	i = 0;
	while (s[i])
	{	
		while (s[i] == c)
			i++;
		if (s[i])
			split_size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (split_size);
}

char	*str_malloc(char *s, char c)
{
	int		len;
	char	*arr;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s, len + 1);
	return (arr);
}

void	split_free(char	**split, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(split[j++]);
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		split_size;
	int		i;

	split_size = split_size_function((char *)s, c);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (split_size + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			split[i++] = str_malloc((char *)s, c);
		if (split[i] == NULL)
		{
			split_free(split, i);
			return (NULL);
		}
		while (*s != c && *s)
			s++;
	}
	split[i] = NULL;
	return (split);
}
