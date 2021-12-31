/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:44:44 by junekim           #+#    #+#             */
/*   Updated: 2021/12/31 14:05:35 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	is_set(char const c, char const *set)
{
	while (*set)
		if (c == *(set++))
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end], set))
		end--;
	ptr = (char *)malloc((end - start + 1) + 1);
	ft_strlcpy(ptr, &s1[start], (end - start + 1) + 1);
	return (ptr);
}
