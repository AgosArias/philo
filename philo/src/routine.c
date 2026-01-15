/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:14:00 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/13 09:44:44 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_all_alive(t_data *data)
{
	int live;

	live = 0;
	pthread_mutex_lock(&data->state_lock);
	live = data->all_alive;
	pthread_mutex_unlock(&data->state_lock);
	return live;
}
int	ft_set_all_alive(t_data *data, int set)
{
	int live;

	live = 0;
	pthread_mutex_lock(&data->state_lock);
	data->all_alive = set;
	pthread_mutex_unlock(&data->state_lock);
	return live;
}

void	*ft_routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (ft_get_all_alive(philo->data) == 0)
			break;
		ft_eat(philo);
		if (ft_get_all_alive(philo->data) == 0)
			break;
		ft_sleep(philo);
		if (ft_get_all_alive(philo->data) == 0)
			break;
		ft_think(philo);
	}
	return (NULL);
}
