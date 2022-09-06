/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 01:20:00 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 01:22:03 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_mutex_time(t_philo *p)
{
	pthread_mutex_lock(&(p->time_mutex));
	p->start_time = get_time();
	pthread_mutex_unlock(&(p->time_mutex));
}
