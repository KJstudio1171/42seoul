/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:55:33 by junekim           #+#    #+#             */
/*   Updated: 2021/09/12 15:39:06 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	putchar_row_end(char *rush, int j, int x);
void	putchar_row_not_end(char *rush, int j, int y);
void	ft_putchar(int ch);

void	rush00(int x, int y)
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
				putchar_row_end("o-| ", j, x);
			else
				putchar_row_not_end("o-| ", j, y);
		}
		j = 0;
		printf("\n");
	}
}

void	putchar_row_end(char *rush, int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar(rush[0]);
	else
		ft_putchar(rush[1]);
}

void	putchar_row_not_end(char *rush, int j, int y)
{
	if (j == 1 || j == y)
		ft_putchar(rush[2]);
	else
		ft_putchar(rush[3]);
}

void	ft_putchar(int ch)
{
	printf ("%c", ch);
}

int	main(void)
{
	rush00 (1, 5);
	return (0);
}
