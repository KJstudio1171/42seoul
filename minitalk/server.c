/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:59:05 by junekim           #+#    #+#             */
/*   Updated: 2022/06/21 19:15:04 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_pid(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	if (!pid)
		return (0);
	write(1, "PID: ", 5);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 1);
	free(pid);
	return (1);
}

void	signal_to_string(int signo)
{
	static int	len;
	static char	c;

	if (signo == SIGUSR1)
	{
		if (len < 7)
			c = c << 1;
		len++;
	}
	else if (signo == SIGUSR2)
	{
		c = c | 1;
		if (len < 7)
			c = c << 1;
		len++;
	}
	if (len == 8)
	{
		write(1, &c, 1);
		len = 0;
		c = 0;
	}
}

int	main(void)
{
	int					i;
	struct sigaction	sig;

	sig.sa_handler = signal_to_string;
	i = print_pid();
	if (!i)
	{
		write(1, "ft_atoi malloc error", 20);
		return (0);
	}
	if (sigaction(SIGUSR1, &sig, NULL) || sigaction(SIGUSR2, &sig, NULL))
	{
		write(1, "sigaction error", 15);
		return (0);
	}
	while (1)
		pause();
	return (0);
}
