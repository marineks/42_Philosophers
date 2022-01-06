/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/06 17:22:53 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
**	Après avoir mangé et dormi, le philosophe doitpenser tant qu'il n'a pas
**  deux fourchettes pour remanger 
*/
void	make_philo_think(t_philo *philo, t_data *data)
{
	struct timeval	end;
	
	pthread_mutex_lock(&data->print);
	usleep(data->time_to_eat * 1000);
    gettimeofday (&end, NULL);
	data->elapsed_time = get_time(end) - data->elapsed_time;
	printf("%ld ms | %d is thinking 🤔\n", data->elapsed_time, philo->id);
	philo->has_thought = true;
	pthread_mutex_unlock(&data->print);
}

// void	make_philo_think(t_philo *philo)
// {
// 	pthread_mutex_lock(&data->mutex);
// 	printf("Test \n");
// 	usleep(data->);
//     gettimeofday (&end, NULL);
// 	data->elapsed_time = get_time(end);
// 	printf("Time in milliseconds: %ld milliseconds\n", data->elapsed_time);
// 	pthread_mutex_unlock(&data->mutex);
// }