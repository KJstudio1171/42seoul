/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:11 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 06:42:28 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_sleep_thinking(t_philo_manager *manager, t_philo *p)
{
	long long	start_time;
	long long	finish_time;
	int			is_die;

	is_die = philo_print(manager, p, "is sleeping");
	start_time = get_time();
	while (!is_die)
	{
		finish_time = get_time();
		if ((finish_time - start_time) >= manager \
		->time_to_sleep)
			break ;
		usleep(100);
	}
	is_die = philo_print(manager, p, "is thinking");
	return (is_die);
}

static int	philo_fork(t_philo_manager *manager, pthread_mutex_t *m, t_philo *p)
{
	pthread_mutex_lock(m);
	return (philo_print(manager, p, "has taken a fork"));
}

static int	philo_eat(t_philo_manager *manager, t_philo *p)
{
	int	is_die;

	is_die = philo_print(manager, p, "is eating");
	philo_mutex_time(p);
	while (!is_die)
	{
		p->finish_time = get_time();
		pthread_mutex_lock(&(p->time_mutex));
		if ((p->finish_time - p->start_time) >= manager ->time_to_eat)
		{
			pthread_mutex_unlock(&(p->time_mutex));
			break ;
		}
		pthread_mutex_unlock(&(p->time_mutex));
		usleep(100);
	}
	pthread_mutex_lock(&(p->eat_mutex));
	p->num_eat++;
	pthread_mutex_unlock(&(p->eat_mutex));
	return (is_die);
}

void	philo_act_one(t_philo *p)
{
	philo_fork(p->manager, &(p->manager->forks[p->left]), p);
	pthread_mutex_unlock(&(p->manager->forks[p->left]));
	pthread_mutex_lock(&(p->die_mutex));
	while (!p->is_die)
	{
		pthread_mutex_unlock(&(p->die_mutex));
		usleep(1000);
		pthread_mutex_lock(&(p->die_mutex));
	}
	pthread_mutex_unlock(&(p->die_mutex));
	return ;
}

void	philo_act(t_philo *p)
{
	int	is_die;

	is_die = 0;
	pthread_mutex_lock(&(p->manager->forks[p->num - 1]));
	pthread_mutex_unlock(&(p->manager->forks[p->num - 1]));
	philo_mutex_time(p);
	p->finish_time = get_time();
	if (p->num % 2)
		usleep(2000);
	while (!is_die)
	{
		is_die = philo_fork(p->manager, &(p->manager->forks[p->right]), p);
		is_die = philo_fork(p->manager, &(p->manager->forks[p->left]), p);
		is_die = philo_eat(p->manager, p);
		pthread_mutex_unlock(&(p->manager->forks[p->right]));
		pthread_mutex_unlock(&(p->manager->forks[p->left]));
		is_die = philo_sleep_thinking(p->manager, p);
		usleep(100);
	}
	return ;
}
