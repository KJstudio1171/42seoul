/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 00:38:59 by junekim           #+#    #+#             */
/*   Updated: 2022/09/06 12:57:29 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_manager(int argc, char **argv, t_philo_manager *manager)
{
	manager->stop = 0;
	manager->philo_index = 0;
	manager->flag = argc - 5;
	manager->num_philos = philo_atoi(argv[1]);
	manager->time_to_die = philo_atoi(argv[2]);
	manager->time_to_eat = philo_atoi(argv[3]);
	manager->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		manager->times_philo_must_eat = philo_atoi(argv[5]);
	else
		manager->times_philo_must_eat = 0;
	return ;
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
		manager->philos[i].left = i;
		manager->philos[i].right = (i + 1) % manager->num_philos;
		manager->philos[i].num_eating = 0;
		i++;
	}
	return ;
}

int	init_mutex(t_philo_manager *manager)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(manager->shell), NULL))
		return (1);
	while (i < manager->num_philos)
	{
		if (pthread_mutex_init(&(manager->forks[i]), NULL))
		{
			philo_free(manager);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philo_create(t_philo_manager *manager, t_philo_act *act_info)
{
	int	i;

	i = 1;
	manager->philo_index = 0;
	manager->start_time = get_time();
	manager->philos[0].start_time = get_time();
	manager->philos[0].finish_time = get_time();
	if (pthread_create(&(manager->philos[0].philo_t), \
	NULL, (void *)philo_act_one, (void *)&(act_info[0])))
		return (1);
	usleep(1000);
	while (i < manager->num_philos)
	{
		manager->philo_index = i;
		manager->philos[i].start_time = get_time();
		manager->philos[i].finish_time = get_time();
		if (pthread_create(&(manager->philos[i].philo_t), \
		NULL, (void *)philo_act, (void *)&(act_info[i])))
			return (1);
		usleep(1000);
		i++;
	}
	return (0);
}
