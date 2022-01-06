/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/06 17:22:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/*
**	This function stops and ends the simulation:
**	- First it prints the time of death (protected by a mutex)
**	- Then it destroys the mutex, frees the allocated ressources and
**	  exits the program.
*/
void	stop_simulation(t_data *data, t_philo *philo)
{
	struct timeval	end;
	
	pthread_mutex_lock(&data->print);
	gettimeofday (&end, NULL);
	data->elapsed_time = get_time(end);
	printf("%ld ms | %d died 😵\n", data->elapsed_time, philo->id);
	pthread_mutex_unlock(&data->print);
	end_simulation(data);
	exit(1);
}