/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:42:29 by junekim           #+#    #+#             */
/*   Updated: 2022/05/04 17:40:06 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr(char *s, int *num)
{
	if (s == NULL)
		counter_write(1, "(null)", 6, num);
	else
		counter_write(1, s, ft_strlen(s), num);
}

void	ft_putchar(char c, int *num)
{
	counter_write(1, &c, 1, num);
}
