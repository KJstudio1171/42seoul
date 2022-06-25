/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:59:22 by junekim           #+#    #+#             */
/*   Updated: 2022/06/21 19:03:04 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *string)
{
	int		len;
	int		i;
	int		j;
	char	c;

	len = ft_strlen(string);
	i = 0;
	while (i < len)
	{
		j = 0;
		c = string[i];
		while (8 > j)
		{
			if (((c >> (7 - j)) & 1) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
		}
		usleep(500);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "usage errror", 12);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
