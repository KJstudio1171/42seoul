/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:53:03 by junekim           #+#    #+#             */
/*   Updated: 2022/09/06 12:55:51 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_free_destroy(t_philo_manager *manager)
{
	philo_destroy(manager);
	philo_free(manager);
}

static int	philo(t_philo_manager *manager, t_philo_act *act_info)
{
	int	i;

	i = 0;
	if (philo_create(manager, act_info))
	{
		pthread_mutex_destroy(&(manager->shell));
		philo_free_destroy(manager);
		return (1);
	}
	if (philo_stop(manager))
	{
		pthread_mutex_destroy(&(manager->shell));
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

static int	malloc_philo_act(t_philo_manager *manager, t_philo_act **act_info)
{
	int	i;

	i = 0;
	*act_info = (t_philo_act *)malloc(sizeof(t_philo_act) \
	* manager->num_philos);
	if (!(*act_info))
	{
		philo_free(manager);
		return (1);
	}
	while (i < manager->num_philos)
	{
		(*act_info)[i].manager = manager;
		(*act_info)[i].philo = &(manager->philos[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_manager	manager;
	t_philo_act		*act_info;

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
	if (malloc_philo_act(&manager, &act_info))
		return (print_error("malloc"));
	if (philo(&manager, act_info))
	{
		philo_free_destroy(&manager);
		free(act_info);
		return (print_error("pthread"));
	}
	philo_free_destroy(&manager);
	free(act_info);
	return (0);
}
