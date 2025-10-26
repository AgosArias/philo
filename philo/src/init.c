/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:15:20 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/26 19:25:07 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_philos(t_data *data)
{
	int	i;

	data->philo = (t_philo *) malloc(sizeof(t_philo) * data->num_philo);
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i + 1;
		i++;
	}
	return (0);
}


int	ft_add_data(t_data *data, int argc, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->number_times_eat = ft_atoi(argv[5]);
		if (data->number_times_eat < 1)
		{
			write(2, "Invalid number of number_of_times_to_eat\n", 41);
			return (1);
		}
	}
	else
		data->number_times_eat = 0;
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
