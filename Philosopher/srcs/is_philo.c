/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:35:27 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 06:52:14 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo(t_philo_manager *manager)
{
	if (manager->num_philos < 1 || manager->time_to_die < 1
		|| manager->time_to_eat < 1 || manager->time_to_sleep < 1
		|| manager->times_philo_must_eat < 0)
		return (0);
	return (1);
}
