/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:25:33 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/28 15:50:04 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				think;
	int				sleep;
	pthread_t		thread;
	pthread_attr_t	attr;
	t_data			data;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
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
	pthread_mutex_t	*forks;
}		t_data;

// --- init.c ---
int		ft_init_data(t_data *data, int argc, char **argv);
int		ft_init_philos(t_data *data);

// --- routine.c ---
void	*ft_routine(void *arg);

// --- actions.c ---
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleep(t_philo *philo);

// --- monitor.c ---
void	*monitor(void *arg);

// --- time.c ---
int		get_time(void);
void	smart_sleep(long ms, t_data *data);

// --- utils.c ---
void	print_status(t_philo *philo, char *msg);
int		ft_atoi(const char *str);

#endif
