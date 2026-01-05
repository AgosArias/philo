/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:19:00 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/05 08:54:09 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
    t_data    *data;
    long       now;
    int        i;

    data = (t_data *)arg;
    while (data->all_alive && data->num_philo > i)
    {
        now = get_time();
        if( now - data-> philo[i].eat >= data ->time_to_die)
        {
            data -> all_alive = 0;
            printf("%ld %d died\n",now - data->time_start, data->philo[i].id);
            break;
        }
        i++;
    }
    usleep(1000);
    return (NULL);
}
