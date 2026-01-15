/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 23:10:14 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/14 20:07:42 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
3. checkear int 
*/

void	ft_destroy_program(t_data *data)
{
	if(!data)
		return ;
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->state_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	ft_free_forks(data);
}

void	ft_join_phthread(t_data *data)
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
	
	if (argc != 5 && argc != 6)
	{
		write(2, "Bad Arguments\n", 14);
		return (0);
	}
	++argv;
	if (ft_init_data(&data, argc, argv) == 1)
	{
		ft_destroy_program(&data);
		exit(EXIT_FAILURE);
	}
	if (pthread_create(&data.monitor, NULL, ft_monitor, &data) != 0)
	{
		ft_join_phthread(&data);
		ft_destroy_program(&data);
		return (1);
	}
	pthread_join(data.monitor, NULL);
	ft_join_phthread(&data);
	ft_destroy_program(&data);
	return (0);
}

