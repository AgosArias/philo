/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 00:11:30 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/28 15:12:41 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	philo->eat = philo->data.time_start;
	while (philo->data.all_alive)
	{
		ft_eat(philo);
		ft_think(philo);
		ft_sleep(philo);
	}
}
