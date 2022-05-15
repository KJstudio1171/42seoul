/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:29:48 by junekim           #+#    #+#             */
/*   Updated: 2022/05/04 17:45:08 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	counter_write(int fd, const void *buf, size_t count, int *num);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n, int *num);
void	ft_unsinged_putnbr(unsigned int n, int *num);
int		puthexa(unsigned long n, int mode, int *num);
void	ft_putstr(char *s, int *num);
void	ft_putchar(char c, int *num);

#endif