/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:08:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/17 14:04:04 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	This function is basically a check of the boolean "someone_died"
**	but because this is a ressource which can be accessed by all of the 
**	threads, there must be a mutex to prevent data races.
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
