/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:15:53 by junekim           #+#    #+#             */
/*   Updated: 2021/09/26 12:16:02 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	abs_diff(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

int	checker(char *board, int j, int i)
{
	int	comparison;

	comparison = 0;
	while (comparison < j)
	{
		if (board[comparison] - '0' == i)
			return (0);
		if (abs_diff(comparison, j) == abs_diff(board[comparison] - '0', i))
			return (0);
		comparison++;
	}
	return (1);
}

void	find_all(char *board, int j, int *count)
{
	int	i;

	i = 0;
	if (j == 10)
	{
		(*count)++;
		write(1, board, 10);
		write(1, "\n", 1);
		return ;
	}
	while (i < 10)
	{
		if (checker(board, j, i))
		{
			board[j] = i + '0';
			find_all(board, j + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		count;
	char	board[10];

	count = 0;
	find_all(board, 0, &count);
	return (count);
}
