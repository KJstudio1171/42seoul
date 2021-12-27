/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:15:12 by junekim           #+#    #+#             */
/*   Updated: 2021/09/12 20:37:06 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putchar_edge(int i, int j, int x, int y);
void	putchar_boundary(int i, int j, int x, int y);
void	ft_putchar(int ch);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i <= y)
	{
		while (++j <= x)
		{
			if ((j == 1) && (i == 1 || i == y))
				putchar_edge(i, j, x, y);
			else if ((j == x) && (i == y || i == 1))
				putchar_edge(i, j, x, y);
			else
				putchar_boundary(i, j, x, y);
		}
		j = 0;
		ft_putchar('\n');
	}
}

void	putchar_edge(int i, int j, int x, int y)
{	
	if (x != 1 && y != 1)
	{
		if ((i == 1 && j == 1) || (i == y && j == x))
			ft_putchar('A');
		else
			ft_putchar('C');
	}
	else if (i == 1 && j == 1)
		ft_putchar('A');
	else if (y != 1 && x == 1 && i == y)
		ft_putchar('C');
	else if (y == 1 && x != 1 && j == x)
		ft_putchar('C');
}

void	putchar_boundary(int i, int j, int x, int y)
{
	if (j == 1 || j == x || i == 1 || i == y)
		ft_putchar('B');
	else
		ft_putchar(' ');
}
