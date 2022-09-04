/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 19:16:11 by junekim           #+#    #+#             */
/*   Updated: 2022/09/05 01:21:05 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep_thinking(t_philo_manager *manager, t_philo *philo)
{
	long long	start_time;
	long long	finish_time;

	philo_print(manager, philo->num, "is sleeping");
	start_time = get_time();
	while (!manager->stop)
	{
		finish_time = get_time();
		if ((finish_time - start_time) >= manager \
		->time_to_sleep)
			break ;
		usleep(1);
	}
	philo_print(manager, philo->num, "is thinking");
	return ;
}

static void	philo_fork(t_philo_manager *manager, pthread_mutex_t *mutex, int n)
{
	pthread_mutex_lock(mutex);
	philo_print(manager, n, "has taken a fork");
}

static void	philo_eat(t_philo_manager *manager, t_philo *philo)
{
	philo_print(manager, philo->num, "is eating");
	philo->start_time = get_time();
	while (!manager->stop)
	{
		philo->finish_time = get_time();
		if ((philo->finish_time - philo->start_time) >= manager \
		->time_to_eat)
			break ;
		usleep(1);
	}
	return ;
}

void	philo_act_one(t_philo_act *act_info)
{
	while (!act_info->manager->stop)
	{
		philo_fork(act_info->manager, &(act_info->manager->forks[act_info->\
		philo->right]), act_info->philo->num);
		if (act_info->manager->num_philos != 1)
		{
			philo_fork(act_info->manager, &(act_info->manager->forks[act_info->\
			philo->left]), act_info->philo->num);
			philo_eat(act_info->manager, act_info->philo);
			act_info->philo->num_eating += 1;
			pthread_mutex_unlock(&(act_info->manager->\
			forks[act_info->philo->right]));
		}
		pthread_mutex_unlock(&(act_info->manager->forks[act_info->\
		philo->left]));
		if (act_info->manager->num_philos != 1)
			philo_sleep_thinking(act_info->manager, act_info->philo);
		else
			while (!act_info->manager->stop)
				;
	}
	return ;
}

void	philo_act(t_philo_act *act_info)
{
	while (!act_info->manager->stop)
	{
		philo_fork(act_info->manager, &(act_info->manager->forks[act_info->\
		philo->left]), act_info->philo->num);
		philo_fork(act_info->manager, &(act_info->manager->forks[act_info->\
		philo->right]), act_info->philo->num);
		philo_eat(act_info->manager, act_info->philo);
		act_info->philo->num_eating += 1;
		pthread_mutex_unlock(&(act_info->manager->forks[act_info->\
		philo->right]));
		pthread_mutex_unlock(&(act_info->manager->forks[act_info->\
		philo->left]));
		philo_sleep_thinking(act_info->manager, act_info->philo);
	}
	return ;
}
