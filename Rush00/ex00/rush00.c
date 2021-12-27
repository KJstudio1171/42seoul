/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <junekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:18:25 by junekim           #+#    #+#             */
/*   Updated: 2021/09/12 16:18:36 by junekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	putchar_row_end(char *ch, int j, int x);
void	putchar_row_not_end(char *ch, int j, int x);
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
			if (i == 1 || i == y)
				putchar_row_end("o-| ", j, x);
			else
				putchar_row_not_end("o-| ", j, x);
		}
		j = 0;
		ft_putchar('\n');
	}
}

void	putchar_row_end(char *ch, int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar(ch[0]);
	else
		ft_putchar(ch[1]);
}

void	putchar_row_not_end(char *ch, int j, int x)
{
	if (j == 1 || j == x)
		ft_putchar(ch[2]);
	else
		ft_putchar(ch[3]);
}
