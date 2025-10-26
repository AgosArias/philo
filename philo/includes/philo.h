/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:25:33 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/26 20:49:18 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int	id;
	int	eat;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_times_eat;
	t_philo			*philo;
	pthread_mutex_t	*forks;
}		t_data;

// --- init.c ---
int		ft_init_data(t_data *data, int argc, char **argv);
int		ft_init_philos(t_data *data);

// --- utils.c ---
int		ft_atoi(const char *str);

#endif
