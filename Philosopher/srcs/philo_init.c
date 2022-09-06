/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:38:59 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 06:46:16 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_manager(int argc, char **argv, t_philo_manager *manager)
{
	manager->stop = 0;
	manager->is_six = argc - 5;
	manager->num_philos = philo_atoi(argv[1]);
	manager->time_to_die = philo_atoi(argv[2]);
	manager->time_to_eat = philo_atoi(argv[3]);
	manager->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		manager->times_philo_must_eat = philo_atoi(argv[5]);
	else
		manager->times_philo_must_eat = 0;
}

int	init_malloc(t_philo_manager *manager)
{
	manager->philos = (t_philo *)malloc(sizeof(t_philo) * manager->num_philos);
	if (!manager->philos)
		return (1);
	manager->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* manager->num_philos);
	if (!manager->forks)
	{
		free(manager->philos);
		return (1);
	}
	return (0);
}

void	init_philo(t_philo_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->num_philos)
	{
		manager->philos[i].num = i + 1;
		manager->philos[i].is_die = 0;
		manager->philos[i].start_time = get_time();
		manager->philos[i].finish_time = get_time();
		manager->philos[i].left = i;
		manager->philos[i].right = (i + 1) % manager->num_philos;
		manager->philos[i].num_eat = 0;
		manager->philos[i].manager = manager;
		i++;
	}
	return ;
}

int	init_mutex(t_philo_manager *manager)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(manager->shell_mutex), NULL))
		return (1);
	while (i < manager->num_philos)
	{
		if (pthread_mutex_init(&(manager->philos[i].eat_mutex), NULL))
			return (1);
		else if (pthread_mutex_init(&(manager->philos[i].die_mutex), NULL))
			return (1);
		else if (pthread_mutex_init(&(manager->philos[i].time_mutex), NULL))
			return (1);
		else if (pthread_mutex_init(&(manager->forks[i]), NULL))
			return (1);
		i++;
	}
	return (0);
}
