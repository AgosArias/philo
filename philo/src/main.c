/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:01:11 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/05 00:17:41 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_data(t_data *data)
{
	int	i;

	i = -1;
	if (!data)
		return ;
	if (data->philo)
		free(data->philo);
	if (data->forks)
	{
		while (++i < data->num_philo)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
}
int	ft_launch_threads(t_data *data)
{
	int i;

	i = 0;
	while (i< data->num_philo)
	{
		if(pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]) != 0)
		{
			data->all_alive = 0;
			while (--i >= 0)
				pthread_join(data->philo[i].thread, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_t	mon;

	if (argc != 5 && argc != 6)
	{
		write(2, "Bad Arguments\n", 14);
		exit(EXIT_FAILURE);
	}
	if (ft_init_data(&data, argc, argv) == 1)
		exit(EXIT_FAILURE);

	if (ft_init_philos(&data) == 1)
		exit(EXIT_FAILURE);
	if (ft_launch_threads(&data) == 1)
	{
		ft_destroy_data(&data);
		return (1);
	}
	if (pthread_create(&mon, NULL, monitor, &data) != 0)
	{
		data.all_alive = 0;
		ft_join_threads(&data);
		ft_destroy_data(&data);
		return (1);
	}
	pthread_join(mon, NULL);
	ft_join_threads(&data);
	ft_destroy_data(&data);
	return (0);
}
