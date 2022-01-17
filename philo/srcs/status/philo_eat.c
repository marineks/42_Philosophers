/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/17 13:59:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	Each philosopher must eat in order to stay alive.
**	In this function :
**	- There are two locks for each fork picked up (left and right)
**	- The philosopher eats for <time_to_eat> milliseconds;
**	- The time of the last meal eaten by the philosopher is updated;
**	- Usleep of the <time to eat> * 1000 to convert it in milliseconds
**	- Increase of the count_meals in the case where the option <nb of times
**		the philos must eat> is set.
**	- Unlock of all the mutexes that were locked beforehand
*/
void	make_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork", GREEN);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork", GREEN);
	print_status(philo, "is eating 🤤", PURPLE);
	pthread_mutex_lock(&philo->data->last_meal);
	philo->last_meal_eaten = get_time();
	pthread_mutex_unlock(&philo->data->last_meal);
	usleep(philo->data->time_to_eat * 1000);
	philo->nb_meals_to_eat--;
	pthread_mutex_lock(&philo->data->all_meals);
	philo->data->count_meals++;
	pthread_mutex_unlock(&philo->data->all_meals);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
