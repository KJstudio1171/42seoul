/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:54:35 by junekim           #+#    #+#             */
/*   Updated: 2021/09/19 01:45:32 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int len_1 = 0;
	int len_2 = 0;
	int i = 0;
	while(*str++)
		len_1++;
	while(*to_find++)
		len_2++;
	
	if(!len_2)
		return str;
	while(len_1>=len_2)
	{
		len_1--;
		while(i++ < len_2)
		{
			if(str[i] != to_find[i])
				break;
		}
		if(i==len_2)
			return str;
		str++;
	}
	return 0;
	
}