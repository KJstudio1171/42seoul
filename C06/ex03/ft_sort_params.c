/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 00:16:50 by junekim           #+#    #+#             */
/*   Updated: 2021/09/23 01:02:26 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char **argv)
{	
	int		i;
	int		j;
	int		k;
	int		t;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			while (argv[i][k] && argv[j][k])
			{
				if (argv[i][k] > argv[j][k])
				{
					swap(&argv[i], &argv[j]);
					break ;
				}
				else if(argv[i][k] < argv[j][k])
					break ;
				k++;
			}
			k = 0;
		}
	}
	t = 1;
	while (argc > t)
	{
		while (*argv[t])
			write(1, argv[t]++, 1);
		write(1, "\n", 1);
		t++;
	}
	return (0);
}
