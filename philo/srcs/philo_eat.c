/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/04 16:16:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	make_philo_eat(t_philo *philo, t_data *data)
{
	struct timeval	end;
	
	pthread_mutex_lock(&data->mutex);
	usleep(data->time_to_eat * 1000);
    gettimeofday (&end, NULL);
	data->elapsed_time = get_time(end) - data->elapsed_time;
	printf("%ld ms | %d is eating 🤤\n", data->elapsed_time, philo->id);
	philo->has_eaten = true;
	pthread_mutex_unlock(&data->mutex);
}