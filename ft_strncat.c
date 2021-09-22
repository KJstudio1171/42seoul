/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:50:25 by junekim           #+#    #+#             */
/*   Updated: 2021/09/19 00:53:16 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *tmp = dest;
	if(nb)
	{
		while(*dest)
			dest++;
		while((*dest++ = *src++) != 0)
		{
			if(--nb == 0)
			{
				*dest = '\0';
				break;
			}
		}
	}
	return tmp;
}