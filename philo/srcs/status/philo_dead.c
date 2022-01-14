/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 18:40:42 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	This function stops and ends the simulation:
**	- First it prints the time of death (protected by a mutex)
**	- Then it destroys the mutex, frees the allocated ressources and
**	  exits the program.
*/
int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->someone_died == true)
	{
		pthread_mutex_unlock(&philo->data->death);
		return (FAILURE);
	}
	pthread_mutex_unlock(&philo->data->death);
	return (SUCCESS);
}