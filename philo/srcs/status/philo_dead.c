/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 18:30:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	This function stops and ends the simulation:
**	- First it prints the time of death (protected by a mutex)
**	- Then it destroys the mutex, frees the allocated ressources and
**	  exits the program.
*/
void	stop_simulation(t_philo *philo)
{
	philo->data->elapsed_time = get_time();
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms | %d died 😵\n", philo->data->elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->data->print);
	end_simulation(philo->data);
	exit(1);
}