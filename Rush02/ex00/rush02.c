/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jajoo <jajoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:14:27 by jajoo             #+#    #+#             */
/*   Updated: 2021/09/26 17:15:06 by jajoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str);

void	ft_print_value(char *str);

int		ft_is_whitespace(char c);

int		ft_is_operator(char c);

int		ft_is_number(char c);

char	**ft_create_sarr(int nlen)
{
	char	**sarr;
	int		i;
	int		j;

	sarr = (char **)malloc(sizeof(char *) * nlen);
	if (!sarr)
		return (0);
	i = 0;
	while (i < nlen)
	{
		sarr[i] = (char)malloc(sizeof(char) * (nlen - i + 1));
		if (!sarr[i])
			return (0);
	}
	i = -1;
	while (++i < nlen)
	{
		j = -1;
		while (++j < nlen - i + 1)
			sarr[i][j] = '0';
		sarr[i][nlen - i] = '\0';
	}
	return (sarr);
}

void	ft_write_value(char *stop, int *i)
{
	while (ft_is_whitespace(stop[*i]))
		(*i)++;
	if (stop[*i] == ':')
		(*i)++;
	while (ft_is_whitespace(stop[*i]))
		(*i)++;
	while (stop[*i] >= ' ' && stop[*i] <= '~')
	{
		write(1, stop + *i, 1);
		(*i)++;
	}
}

void	ft_before_num(int *i, int *is_zero)
{
	while (ft_is_whitespace(stop[*i]))
		(*i)++;
	while (ft_is_operator(stop[*i]))
	{
		if (ft_is_operator(stop[*i + 1]) && !*(is_zero))
			*is_zero = 1;
		if (stop[*i] == '-' && stop[*i + 1] != '0')
		{
			write(1, "Error", 5);
			return (0);
		}
		*(i)++;
	}
}

char	**ft_sarr(char *stop)
{
	int		i;
	int		count;
	int		is_zero;
	char	**sarr;

	is_zero = 0;
	i = 0;
	ft_before_num(&i, &is_zero);
	count = i;
	while (ft_is_number(stop[count]))
		count++;
	count -= i;
	if (is_zero)
		ft_create_sarr(1);
	else
	{
		ft_create_sarr(count);
		while (ft_is_number(stop[i]))
		{
			sarr[i][0] = stop[i];
			i++;
		}
	}
	ft_write_value(stop, &i);
	return (sarr);
}
