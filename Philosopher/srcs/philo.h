/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:30:03 by junekim           #+#    #+#             */
/*   Updated: 2022/09/07 03:06:46 by junekim          ###   ########seoul.kr  */
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
	pthread_t				philo_t;
	int						num;
	int						left;
	int						right;
	int						num_eat;
	int						is_die;
	long long				start_time;
	long long				finish_time;
	pthread_mutex_t			time_mutex;
	pthread_mutex_t			eat_mutex;
	pthread_mutex_t			die_mutex;
	struct s_philo_manager	*manager;
}	t_philo;

typedef struct s_philo_manager {
	long long		start_time;
	int				stop;
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_philo_must_eat;
	int				is_six;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	shell_mutex;
}	t_philo_manager;

int			philo_atoi(const char *nptr);
void		philo_act(t_philo *p);
void		philo_act_one(t_philo *p);
long long	get_time(void);
int			print_error(char *string);
int			philo_print(t_philo_manager *manager, t_philo *p, char *string);
int			philo_stop(t_philo_manager *manager);
int			philo_create(t_philo_manager *manager);
int			init_malloc(t_philo_manager *manager);
void		init_manager(int argc, char **argv, t_philo_manager *manager);
void		init_philo(t_philo_manager *manager);
int			init_mutex(t_philo_manager *manager);
void		philo_destroy(t_philo_manager *manager);
void		philo_free(t_philo_manager *manager);
int			is_philo(t_philo_manager *manager);
void		philo_mutex_time(t_philo *p);

#endif