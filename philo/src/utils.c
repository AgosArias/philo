/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:51:47 by aarias-d          #+#    #+#             */
/*   Updated: 2026/01/10 23:30:54 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

int	ft_get_next_char(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)

{
	int	num;
	int	i;
	int	symbol;

	num = 0;
	i = ft_get_next_char(str);
	symbol = 1;
	if (str[i] == '-')
	{
		symbol = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * symbol);
}

long	ft_get_time(void)
{
	struct timeval	tv;
	long			time;

	if (gettimeofday(&tv, NULL))
		return (1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}


void	print_status(t_philo *philo, char *msg)
{
	long	now;

	if(!ft_get_all_alive)
		return ;
	pthread_mutex_lock(&philo->data->write_lock);
	now = ft_get_time() - philo->data->time_start;
	printf("%ld %d %s\n", now, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}
