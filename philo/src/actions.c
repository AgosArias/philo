/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:38:58 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/28 15:49:30 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	philo->think = get_time();
	write(1, "is thinking\n", 12);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->lf);
	write(1, "has taken a fork\n", 17);
	pthread_mutex_lock(philo->rf);
	write(1, "has taken a fork\n", 17);
	philo->eat = get_time();
	write(1, "is eating\n", 10);
	pthread_mutex_unlock(philo->lf);
	pthread_mutex_unlock(philo->rf);
}


void	ft_sleep(t_philo *philo)
{
	philo->sleep = get_time();
	write(1, "is sleeping\n", 12);
}