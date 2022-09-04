/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:30:03 by junekim           #+#    #+#             */
/*   Updated: 2022/09/04 20:51:46 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo {
	pthread_t		philo_t;
	int				num;
	int				left;
	int				right;
	int				num_eating;
	long long		start_time;
	long long		finish_time;
}	t_philo;

typedef struct s_philo_manager {
	long long		start_time;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_philo_must_eat;
	int				flag;
	int				stop;
	int				philo_index;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	shell;
}	t_philo_manager;

typedef struct s_philo_act
{
	t_philo			*philo;
	t_philo_manager	*manager;
}	t_philo_act;

int			philo_atoi(const char *nptr);
void		philo_act(t_philo_act *act_info);
void		philo_act_one(t_philo_act *act_info);
long long	get_time(void);
int			print_error(char *string);
int			philo_print(t_philo_manager *manager, int num, char *string);
void		philo_stop(t_philo_manager *manager);
int			philo_create(t_philo_manager *manager, t_philo_act *act_info);
int			init_malloc(t_philo_manager *manager);
void		init_manager(int argc, char **argv, t_philo_manager *manager);
int			init_philo(t_philo_manager *manager);
int			init_mutex(t_philo_manager *manager);
void		philo_destroy(t_philo_manager *manager);
void		philo_free(t_philo_manager *manager);
int			is_philo(t_philo_manager *manager);



#endif