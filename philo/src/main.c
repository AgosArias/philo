/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:01:11 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/26 19:05:44 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(2, "Bad Arguments\n", 14);
		exit(EXIT_FAILURE);
	}
	if (ft_init_data(&data, argc, argv) == 1)
		exit(EXIT_FAILURE);
	if (ft_init_philos(&data) == 1)
		exit(EXIT_FAILURE);

	return (0);
}