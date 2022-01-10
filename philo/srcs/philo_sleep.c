/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/10 15:59:30 by msanjuan         ###   ########.fr       */
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
void	make_philo_sleep(t_philo *philo)
{
	philo->data->elapsed_time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms | %d is sleeping 😪\n", philo->data->elapsed_time, philo->id + 1);
	philo->has_slept = true;
	pthread_mutex_unlock(&philo->data->print);
	usleep(philo->data->time_to_sleep * 1000);
}