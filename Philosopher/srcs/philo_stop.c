/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:43:53 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 06:09:52 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	num_over_sub(t_philo_manager *manager)
{
	int	j;

	j = 0;
	while (j < manager->num_philos)
	{
		pthread_mutex_lock(&(manager->philos[j].die_mutex));
		manager->philos[j].is_die = 1;
		pthread_mutex_unlock(&(manager->philos[j].die_mutex));
		j++;
	}
}

static void	num_over(t_philo_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->num_philos)
	{
		pthread_mutex_lock(&(manager->philos[i].eat_mutex));
		if (manager->philos[i].num_eat < manager->times_philo_must_eat)
		{
			pthread_mutex_unlock(&(manager->philos[i].eat_mutex));
			break ;
		}
		pthread_mutex_unlock(&(manager->philos[i].eat_mutex));
		i++;
		if (i == manager->num_philos)
		{
			pthread_mutex_lock(&(manager->shell_mutex));
			num_over_sub(manager);
			pthread_mutex_unlock(&(manager->shell_mutex));
			manager->stop = 1;
			return ;
		}
	}
}

static void	time_over_sub(t_philo_manager *manager, int i)
{
	int			j;
	long long	time;

	j = 0;
	pthread_mutex_unlock(&(manager->philos[i].time_mutex));
	pthread_mutex_unlock(&(manager->philos[i].die_mutex));
	pthread_mutex_lock(&(manager->shell_mutex));
	time = get_time();
	printf("%lld %d %s\n", time - manager->start_time \
	, manager->philos[i].num, "died");
	manager->philos[i].is_die = 1;
	while (j < manager->num_philos)
	{
		pthread_mutex_lock(&(manager->philos[j].die_mutex));
		manager->philos[j].is_die = 1;
		pthread_mutex_unlock(&(manager->philos[j].die_mutex));
		j++;
	}
	pthread_mutex_unlock(&(manager->shell_mutex));
}

static void	time_over(t_philo_manager *manager)
{
	int			i;
	long long	time;

	i = 0;
	while (i < manager->num_philos)
	{
		time = get_time();
		pthread_mutex_lock(&(manager->philos[i].die_mutex));
		pthread_mutex_lock(&(manager->philos[i].time_mutex));
		if (manager->time_to_die <= time - manager->philos[i].start_time)
		{
			time_over_sub(manager, i);
			manager->stop = 1;
			return ;
		}
		pthread_mutex_unlock(&(manager->philos[i].time_mutex));
		pthread_mutex_unlock(&(manager->philos[i].die_mutex));
		i++;
	}
	usleep(100);
}

void	philo_stop(t_philo_manager *manager)
{
	while (!manager->stop)
	{
		if (manager->is_six)
			num_over(manager);
		time_over(manager);
	}
}
