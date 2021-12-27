/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:15:54 by junekim           #+#    #+#             */
/*   Updated: 2021/09/28 14:26:28 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*result;
	int					index;
	int					size;

	size = sizeof(struct s_stock_str);
	index = 0;
	result = (struct s_stock_str *)malloc(size * (ac + 1));
	if (!result)
		return (NULL);
	while (index < ac)
	{
		result[index].size = ft_strlen(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		if (!result[index].copy)
			return (NULL);
		index++;
	}
	result[index].size = 0;
	result[index].str = 0;
	result[index].copy = 0;
	return (result);
}
