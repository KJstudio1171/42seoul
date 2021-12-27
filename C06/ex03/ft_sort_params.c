/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:03:52 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 12:25:00 by junekim          ###   ########.fr       */
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

void	ft_print_params(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
}

void	swap_test(int *i, int *j, int *k, char **argv)
{
	while (argv[*i][*k] && argv[*j][*k])
	{
		if (argv[*i][*k] > argv[*j][*k])
		{
			swap(&argv[*i], &argv[*j]);
			break ;
		}
		else if (argv[*i][*k] < argv[*j][*k])
			break ;
		(*k)++;
	}
	if (argv[*j][*k] == '\0')
		swap(&argv[*i], &argv[*j]);
	*k = 0;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			swap_test(&i, &j, &k, argv);
		}
	}
	ft_print_params(argc, argv);
	return (0);
}
