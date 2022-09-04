/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:43:53 by junekim           #+#    #+#             */
/*   Updated: 2022/09/05 01:06:00 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	num_over(t_philo_manager *manager)
{
	int	i;

	i = 0;
	while (i < manager->num_philos)
	{
		if (manager->philos[i].num_eating < manager->times_philo_must_eat)
			break ;
		i++;
		if (i == manager->num_philos)
		{
			manager->stop = 1;
			return (1);
		}
	}
	return (0);
}

static int	time_over(t_philo_manager *manager)
{
	int			i;
	long long	time;

	i = 0;
	while (i < manager->num_philos)
	{
		time = get_time();
		if (manager->time_to_die <= time - manager->philos[i].start_time)
		{
			manager->stop = 1;
			if (pthread_mutex_lock(&(manager->shell)))
				return (1);
			time = get_time();
			printf("%lld %d %s\n", time - manager->start_time \
			, manager->philos[i].num, "died");
			if (pthread_mutex_unlock(&(manager->shell)))
				return (1);
			pthread_mutex_destroy(&(manager->shell));
		}
		i++;
	}
	return (0);
}

void	philo_stop(t_philo_manager *manager)
{
	while (!manager->stop)
	{
		if (manager->flag)
			if (num_over(manager))
				return ;
		if (time_over(manager))
			return ;
	}
}
