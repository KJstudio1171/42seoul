/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:53:03 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 04:03:50 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_free_destroy(t_philo_manager *manager)
{
	philo_destroy(manager);
	philo_free(manager);
}

static int	philo(t_philo_manager *manager)
{
	int	i;

	i = 0;
	if (philo_create(manager))
	{
		pthread_mutex_destroy(&(manager->shell_mutex));
		philo_free_destroy(manager);
		return (1);
	}
	if (philo_stop(manager))
	{
		pthread_mutex_destroy(&(manager->shell_mutex));
		philo_free_destroy(manager);
		return (1);
	}
	while (i < manager->num_philos)
	{
		if (pthread_join(manager->philos[i].philo_t, NULL))
		{
			philo_free_destroy(manager);
			return (1);
		}
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
		return (print_error("mutex"));
	if (philo(&manager))
	{
		philo_free_destroy(&manager);
		return (print_error("pthread"));
	}
	usleep(100000);
	philo_free_destroy(&manager);
	return (0);
}
