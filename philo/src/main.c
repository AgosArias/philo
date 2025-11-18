/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:01:11 by aarias-d          #+#    #+#             */
/*   Updated: 2025/11/18 19:01:04 by aarias-d         ###   ########.fr       */
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


int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*p;
	int		i;

	if (argc != 5 && argc != 6)
	{
		write(2, "Bad Arguments\n", 14);
		exit(EXIT_FAILURE);
	}
	if (ft_init_data(&data, argc, argv) == 1)
		exit(EXIT_FAILURE);

	if (ft_init_philos(&data) == 1)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < data.num_philo)
	{
		p = &data.philo[i];
		if (pthread_create(&p->thread, NULL, ft_routine, p) != 0)
			break ;
		i++;
	}

	ft_destroy_data(&data);
	return (0);
}
