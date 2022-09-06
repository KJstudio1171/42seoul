/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:53:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/06 12:57:38 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

int	print_error(char *string)
{
	printf("Error\n");
	printf("check %s\n", string);
	return (1);
}

int	philo_print(t_philo_manager *manager, int num, char *string)
{
	long long	time;

	time = get_time();
	if (time == -1)
		return (1);
	usleep(10);
	if (!manager->stop)
	{
		if (pthread_mutex_lock(&(manager->shell)))
			return (1);
		printf("%lld %d %s\n", time - manager->start_time, num, string);
		if (pthread_mutex_unlock(&(manager->shell)))
			return (1);
	}
	return (0);
}

void	philo_destroy(t_philo_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->num_philos)
	{
		pthread_mutex_destroy(&(manager->forks[i]));
		i++;
	}
	return ;
}

void	philo_free(t_philo_manager *manager)
{
	free (manager->philos);
	free(manager->forks);
	return ;
}
