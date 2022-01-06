/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/06 17:22:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
** This function :
**	- Makes one philosopher sleep for <time_to_sleep> milliseconds;
**	- Usleep * 1000 to convert in milliseconds;
**	- Displays the time with the corresponding philo;
**	- Set the bool "has slept" to true.
**	- Use of a mutex to prevent data race
*/
void	make_philo_sleep(t_philo *philo, t_data *data)
{
	struct timeval	end;
	
	pthread_mutex_lock(&data->print);
	usleep(data->time_to_sleep * 1000);
    gettimeofday(&end, NULL);
	data->elapsed_time = get_time(end) - data->elapsed_time;
	printf("%ld ms | %d is sleeping 😪\n", data->elapsed_time, philo->id);
	philo->has_slept = true;
	pthread_mutex_unlock(&data->print);
}