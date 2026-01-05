/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:15:20 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/05 09:09:20 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (1);
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (1);
		}
	}
	return (0);
}

int	ft_init_philos(t_data *data)
{
	int	i;

	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->num_philo);
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].lf = &data->forks[i];
		data->philo[i].rf = &data->forks[(i + 1) % data->num_philo];
		data->philo[i].last_meal = data->time_start;
		data->philo[i].meals_eaten = 0;
		data->philo[i].eat = 0;
		data->philo[i].think = 0;
		data->philo[i].sleep = 0;
		i++;
	}
	return (0);
}


int	ft_add_data(t_data *data, int argc, char **argv)
{
	struct timeval	tv;

	if (argc != 5 && argc != 6)
		return (1);
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->number_times_eat = ft_atoi(argv[5]);
		if (data->number_times_eat < 1)
			return (1);
	}
	else
		data->number_times_eat = 0;
	if (data->num_philo < 1 || ft_init_mutexes(data) == 1)
		return (1);
	data->all_alive = 1;
	if (gettimeofday(&tv, NULL))
		return (1);
	data->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	if (ft_add_data(data, argc, argv) == 1)
		return (1);
	if (data->num_philo < 1)
	{
		write(2, "Invalid number of philosofers\n", 30);
		return (1);
	}
	if (data->time_to_die < 1)
	{
		write(2, "Invalid number of time_to_die\n", 30);
		return (1);
	}
	if (data->time_to_eat < 1)
	{
		write(2, "Invalid number of time_to_eat\n", 30);
		return (1);
	}
	if (data->time_to_sleep < 1)
	{
		write(2, "Invalid number of time_to_sleep\n", 32);
		return (1);
	}
	return (0);
}
