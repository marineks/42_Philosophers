/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:33:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	Each philosopher must eat in order to stay alive.
**	In this function :
**	- I used a mutex 
*/

void	make_philo_eat(t_philo *philo)
{ 
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken the left fork", GREEN);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken the right fork", GREEN);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken the right fork", GREEN);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken the left fork", GREEN);
	}
	print_status(philo, "is eating 🤤", PURPLE);
	usleep(philo->data->time_to_eat * 1000);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

// philo->has_eaten = true;
// philo->nb_times_must_eat--;
// printf("Le philo %d a mangé %d fois.\n", philo->id, philo->nb_times_must_eat);