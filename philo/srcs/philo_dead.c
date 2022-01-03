/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/03 17:01:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
**	This function stops and end the simulation:
**	- First it prints the time of death (protected by a mutex)
**	- Then it takes destroys the mutex, free the allocated ressources and
**	  exit the program.
*/
void	stop_simulation(t_data *data, t_philo *philo)
{
	struct timeval	end;
	
	pthread_mutex_lock(&data->mutex);
	gettimeofday (&end, NULL);
	data->elapsed_time = get_time(end);
	printf("%ld ms | %d died 😵\n", data->elapsed_time, philo->id);
	pthread_mutex_unlock(&data->mutex);
	end_simulation(data);
	exit(1);
}