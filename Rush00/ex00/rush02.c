/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:14:40 by junekim           #+#    #+#             */
/*   Updated: 2021/09/12 16:14:44 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putchar_row_end(int i, int j, int x, int y);
void	putchar_row_not_end(int j, int x);
void	ft_putchar(int ch);

int		g_ch[4] = {'A', 'B', 'C', ' '};

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
			if (i == 1 || i == y)
				putchar_row_end(i, j, x, y);
			else
				putchar_row_not_end(j, x);
		}
		j = 0;
		ft_putchar('\n');
	}
}

void	putchar_row_end(int i, int j, int x, int y)
{
	if (i == 1 && (j == 1 || j == x))
		ft_putchar(g_ch[0]);
	else if (i == y && (j == 1 || j == x))
		ft_putchar(g_ch[2]);
	else
		ft_putchar(g_ch[1]);
}

void	putchar_row_not_end(int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar(g_ch[1]);
	else
		ft_putchar(g_ch[3]);
}
