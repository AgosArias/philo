/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:25:33 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/13 17:56:12 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_times_eat;
	int				all_alive;
	long			time_start;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	state_lock;
}		t_data;

/* ---------     init.c ----------*/
int	ft_init_data(t_data *data,  char *argv);

/* ---------     utils.c ----------*/
int		ft_atoi(const char *str);
long	ft_get_time(void);

/* ---------     routine.c ----------*/
void *ft_routine(t_philo *philo);
int	ft_get_all_alive(t_data *data);
int	ft_set_all_alive(t_data *data, int set);

/* ---------     monitor.c ----------*/
void	*ft_monitor(t_data *data);

/* ------------ - main.c - ---------*/
void	ft_join_phthread(t_data *data);

/* ------------ - mutex.c - ---------*/
int	ft_init_mutexes(t_data *data);

#endif
