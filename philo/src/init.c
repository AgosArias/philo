/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:16:48 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/15 21:08:07 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(data->philo[i].thread, NULL);
			return(1);
		}
		i++;
	}
	return(0);
}

int	ft_inicial_constants(t_data *data, int argc, char **argv)
{
	struct timeval	tv;

	data->num_philo = ft_atoi(*argv++);
	data->time_to_die = ft_atoi(*argv++);
	data->time_to_eat = ft_atoi(*argv++);
	data->time_to_sleep = ft_atoi(*argv++);
	if(argc == 6)
		data->number_times_eat = ft_atoi(*argv);
	else
		data->number_times_eat = -1;
	data->all_alive = 1;
	if (gettimeofday(&tv, NULL))
		return (1);
	data->time_start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (0);

}

int	ft_init_philos(t_data *data)
{
	int	i;

	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->num_philo);
	if(!data->philo)
		return (1);
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].data = data;
		data->philo[i].last_meal = data->time_start;

		data->philo[i].meals_eaten = 0;
		i++;
	}
	return (0);
}

int	ft_init_data(t_data *data, int argc, char **argv)
{
	/*CHECK INT*/
	if(ft_inicial_constants(data, argc, argv)!= 0)
		return(1);
	if(ft_init_mutexes(data)!= 0)
		return(1);
	if(ft_init_philos(data) != 0)
			return(1);
	if(ft_create_threads(data) != 0)
		return(1);
	return (0);
}