/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:50:06 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 15:56:26 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r' || ch == ' ')
		return (1);
	return (0);
}

int	count_int(int *i, char *str)
{
	int	count;

	count = 0;
	while (is_space(str[*i]))
		(*i)++;
	while (str[*i])
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			break ;
		if (str[*i] != '-' && str[*i] != '+')
			return (-1);
		if (str[*i] == '-')
		{
			count++;
		}
		(*i)++;
	}
	return (count);
}

void	atoi_subfuction(int count, char *str, int *atoi, int *i)
{
	if (count % 2 == 0)
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*atoi *= 10;
			*atoi += (str[(*i)++] - '0');
		}
	}
	else
	{
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*atoi *= 10;
			*atoi -= (str[(*i)++] - '0');
		}
	}
}

int	ft_atoi(char *str)
{
	int	atoi;
	int	count;
	int	i;

	atoi = 0;
	i = 0;
	count = count_int(&i, str);
	if (count == -1)
		return (0);
	atoi_subfuction(count, str, &atoi, &i);
	return (atoi);
}
