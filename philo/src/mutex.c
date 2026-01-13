/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 23:04:20 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/12 23:56:53 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_free_forks(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	data->forks = NULL;
	return (1);
}

int ft_init_forks(t_data *data)
{
	int i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if(!data->forks)
		return (1);
	i = -1;
	while (++i < data->num_philo)
	{
		if(pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i > 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			data->forks = NULL;
			return (1);
		}
	}
	return (0);
}
int	ft_init_mutexes(t_data *data)
{
	if(ft_init_forks(data) != 0)
		return (1);
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
	{
		ft_free_forks(data);
		return (1);
	}	
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		ft_free_forks(data);
		return (1);
	}	
	if (pthread_mutex_init(&data->state_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->write_lock);
		pthread_mutex_destroy(&data->meal_lock);
		ft_free_forks(data);
		return (1);
	}	
	return (0);
}

