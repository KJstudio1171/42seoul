/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:50:40 by junekim           #+#    #+#             */
/*   Updated: 2022/01/14 22:30:11 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c < 128)
		return (1);
	else
		return (0);
}
