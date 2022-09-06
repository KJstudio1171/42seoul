/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:53:03 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 07:01:17 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_create_sub(t_philo_manager *manager)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < manager->num_philos)
	{
		pthread_mutex_lock(&(manager->forks[i]));
		if (pthread_create(&(manager->philos[i].philo_t), \
		NULL, (void *)philo_act, (void *)&(manager->philos[i])))
		{
			while (j < i)
			{
				pthread_mutex_unlock(&(manager->forks[j]));
				pthread_mutex_lock(&(manager->philos[j].die_mutex));
				manager->philos[j].is_die = 1;
				pthread_mutex_unlock(&(manager->philos[j].die_mutex));
				pthread_join(manager->philos[j].philo_t, NULL);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	philo_create(t_philo_manager *manager)
{
	int	i;

	i = 0;
	if (manager->num_philos == 1)
	{
		manager->start_time = get_time();
		if (pthread_create(&(manager->philos[0].philo_t), \
		NULL, (void *)philo_act_one, (void *)&(manager->philos[0])))
			return (1);
		return (0);
	}
	if (philo_create_sub(manager))
		return (1);
	manager->start_time = get_time();
	i = 0;
	while (i < manager->num_philos)
		pthread_mutex_unlock(&(manager->forks[i++]));
	usleep(100);
	return (0);
}

static int	philo(t_philo_manager *manager)
{
	int	i;

	i = 0;
	if (philo_create(manager))
	{
		philo_destroy(manager);
		philo_free(manager);
		return (1);
	}
	philo_stop(manager);
	while (i < manager->num_philos)
	{
		pthread_join(manager->philos[i].philo_t, NULL);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_manager	manager;

	if (argc != 5 && argc != 6)
		return (print_error("argument"));
	init_manager(argc, argv, &manager);
	if (!is_philo(&manager))
		return (print_error("argument"));
	if (init_malloc(&manager))
		return (print_error("malloc"));
	init_philo(&manager);
	if (init_mutex(&manager))
	{
		philo_free(&manager);
		return (print_error("mutex"));
	}
	if (philo(&manager))
	{
		philo_destroy(&manager);
		philo_free(&manager);
		return (print_error("pthread"));
	}
	philo_destroy(&manager);
	philo_free(&manager);
	return (0);
}
