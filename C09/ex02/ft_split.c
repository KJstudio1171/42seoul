/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:50:58 by junekim           #+#    #+#             */
/*   Updated: 2021/09/30 13:21:00 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *charset, char ch)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int	split_size_function(char *str, char *charset)
{
	int		split_size;
	int		i;

	split_size = 0;
	i = 0;
	while (str[i])
	{	
		while (is_charset(charset, str[i]))
			i++;
		if (str[i])
			split_size++;
		while (!is_charset(charset, str[i]) && str[i])
			i++;
	}
	return (split_size);
}

char	*make_str(char *str, char *charset)
{
	int		len;
	int		i;
	char	*arr;

	len = 0;
	i = 0;
	while (!is_charset(charset, str[len]) && str[len])
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		split_size;
	int		i;

	split_size = split_size_function(str, charset);
	i = 0;
	split = (char **)malloc(sizeof(char *) * (split_size + 1));
	while (*str)
	{
		while (is_charset(charset, *str))
			str++;
		if (*str)
			split[i++] = make_str(str, charset);
		while (!is_charset(charset, *str) && *str)
			str++;
	}
	split[i] = NULL;
	return (split);
}
