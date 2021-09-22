/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:32:58 by junekim           #+#    #+#             */
/*   Updated: 2021/09/18 22:58:18 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int len = 0;
	unsigned int i = 0;
	while(src[len])
	{
		len++;
	}

	if(!dest || !src)
		return (0);

	while(i < len && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if(size>0)
	{
		dest[i] = '\0';
	}
	return len;
}

int main()
{
	unsigned int c;
	char a[3];
	char b[] = "string";
	c = ft_strlcpy(a,b,7);
	printf("%d", c);
	printf("%s", a);
}
