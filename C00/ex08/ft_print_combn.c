/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:08:40 by junekim           #+#    #+#             */
/*   Updated: 2021/09/16 16:12:25 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_stack(int n, char *stack)
{
	write(1, stack, n + 1);
	if (stack[0] == 10 - n - 1 + 48)
		return ;
	write(1, ", ", 2);
}

void	recursion(int n, int m, char *stack)
{
	int	i;

	if (n >= m)
	{
		print_stack(n - 1, stack);
		return ;
	}
	if (n == 0)
	{
		i = n;
		while (i < 10 - n + 1 && i < 10)
		{
			stack[n] = i++ + 48;
			recursion(n + 1, m, stack);
		}
	}
	else
	{
		i = stack[n - 1] + 1 - 48;
		while (i < 10 - (m - n) + 1)
		{
			stack[n] = i++ + 48;
			recursion(n + 1, m, stack);
		}
	}
}

void	ft_print_combn(int n)
{
	char	stack[10];

	if (n > 0 && n < 10)
		recursion(0, n, stack);
	return ;
}
