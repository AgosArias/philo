/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:25:33 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/25 18:16:13 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <studio.h>
# include <unistd.h>


typedef struct s_philo
{
	int	eat;
}	t_philo;

typedef struct s_params
{
	int	num_philo;
}	t_params;

#endif
