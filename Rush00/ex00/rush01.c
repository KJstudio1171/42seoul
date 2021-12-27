/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:14:04 by junekim           #+#    #+#             */
/*   Updated: 2021/09/12 16:14:34 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putchar_row_end(int i, int j, int x, int y);
void	putchar_row_not_end(int i, int j, int x, int y);
void	ft_putchar(int ch);

int		g_ch[4] = {'/', '\\', '*', ' '};

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
			if ((i == 1 || i == y) && (j == 1 || j == x))
				putchar_row_end(i, j, x, y);
			else
				putchar_row_not_end(i, j, x, y);
		}
		j = 0;
		ft_putchar('\n');
	}
}

void	putchar_row_end(int i, int j, int x, int y)
{
	if (x == 1 && y == 1)
		ft_putchar(g_ch[0]);
	else if (y == 1 && x == j)
		ft_putchar(g_ch[1]);
	else if (x == 1 && y == i)
		ft_putchar(g_ch[1]);
	else if ((i == 1 && j == 1) || (i == y && j == x))
		ft_putchar(g_ch[0]);
	else
		ft_putchar(g_ch[1]);
}

void	putchar_row_not_end(int i, int j, int x, int y)
{
	if (i == 1 || i == y || j == 1 || j == x)
		ft_putchar(g_ch[2]);
	else
		ft_putchar(g_ch[3]);
}
