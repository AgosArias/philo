/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:15:35 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/14 12:06:15 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_ate(t_data *data)
{
	int	i;

	if (data->number_times_eat <= 0)
		return (0);
	i = 0;
	pthread_mutex_lock(&data->meal_lock);
	while (i< data->num_philo)
	{
		if (data->philo[i].meals_eaten < data->number_times_eat)
		{
			pthread_mutex_unlock(&data->meal_lock);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&data->meal_lock);
	return (1);
}



long	ft_get_lastmeal(t_philo *philo)
{
	long lm;

	pthread_mutex_lock(&philo->data->meal_lock);
	lm = philo->last_meal;
	pthread_mutex_unlock(&philo->data->meal_lock);
	return lm;
}

void	*ft_monitor(void *arg)
{
	t_data *data;
	int     i;

	data = (t_data *) arg;
	while(1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (!ft_get_all_alive(data))
				return (NULL);
			if( ft_get_time() - ft_get_lastmeal(&data->philo[i]) >= data->time_to_die)
			{
				ft_set_all_alive(data, 0);
				pthread_mutex_lock(&data->write_lock);
				printf("%ld %d died\n", ft_get_time() - data->time_start, data->philo[i].id);
				pthread_mutex_unlock(&data->write_lock);
				return (NULL);
			}
			i++;
		}
		if (ft_all_ate(data))
		{
			ft_set_all_alive(data, 0);
			return (NULL);
		}
		usleep(1000);
	}
}




