/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:30:22 by junekim           #+#    #+#             */
/*   Updated: 2022/01/14 22:19:39 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	while (num--)
	{
		if (*((unsigned char *)ptr1) != *((unsigned char *)ptr2))
			return (*((unsigned char *)ptr1) - *((unsigned char *)ptr2));
		else
		{
			ptr1++;
			ptr2++;
			continue ;
		}
	}
	return (0);
}
