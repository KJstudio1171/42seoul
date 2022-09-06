/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:53:36 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 06:49:08 by junekim          ###   ########seoul.kr  */
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

int	philo_print(t_philo_manager *manager, t_philo *p, char *string)
{
	long long	time;

	pthread_mutex_lock(&(manager->shell_mutex));
	pthread_mutex_lock(&(p->die_mutex));
	if (!(p->is_die))
	{
		pthread_mutex_unlock(&(p->die_mutex));
		time = get_time();
		printf("%lld %d %s\n", time - manager->start_time, p->num, string);
		pthread_mutex_unlock(&(manager->shell_mutex));
		return (0);
	}
	pthread_mutex_unlock(&(p->die_mutex));
	pthread_mutex_unlock(&(manager->shell_mutex));
	return (1);
}

void	philo_destroy(t_philo_manager *manager)
{
	int	i;

	i = 0;
	usleep(10000);
	pthread_mutex_destroy(&(manager->shell_mutex));
	while (i < manager->num_philos)
	{
		pthread_mutex_destroy(&(manager->philos[i].time_mutex));
		pthread_mutex_destroy(&(manager->philos[i].die_mutex));
		pthread_mutex_destroy(&(manager->philos[i].eat_mutex));
		pthread_mutex_destroy(&(manager->forks[i]));
		i++;
	}
	return ;
}

void	philo_free(t_philo_manager *manager)
{
	free(manager->philos);
	free(manager->forks);
	return ;
}
