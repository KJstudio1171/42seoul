/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:34:30 by junekim           #+#    #+#             */
/*   Updated: 2021/09/19 00:39:06 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i;
	i = 0;
	while(i<n)
	{
		if(s1[i]==s2[i])
		{
			if(s1[i]=='\0')
				return 0;
			continue;
		}
		else if(s1[i] > s1[2])
			return 1;
		else
			return -1;
	}
	return 0;
}