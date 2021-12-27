/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:43:14 by junekim           #+#    #+#             */
/*   Updated: 2021/09/21 13:21:09 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		len_1;
	int		len_2;
	int		i;
	char	*tmp;

	len_1 = str_len(str);
	len_2 = str_len(to_find);
	if (len_2 == 0)
		return (str);
	while (*str && len_1 >= len_2)
	{
		i = 0;
		len_1--;
		tmp = str;
		while (i < len_2)
		{
			if (*(str + i) != to_find[i])
				break ;
			i++;
		}
		if (i == len_2)
			return (tmp);
		str ++;
	}
	return (0);
}
