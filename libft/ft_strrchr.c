/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:07:43 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:03:18 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len < 0)
	{
		if (str[len] == c)
			return ((char *)&str[len]);
		len--;
	}
	return (NULL);
}
