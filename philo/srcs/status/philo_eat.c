/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 17:22:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	Each philosopher must eat in order to stay alive.
**	In this function :
**	- I used two mutexes for each fork and one for the print (in print status)
**	- To prevent deadlock situations with the mutexes, the "even id" philo
**		must take his left fork first while the "odd id" one will take his
**		right fork first. According to the design of the table, they will
**		therefore try to take the same fork. If one is already taken,
**		the other philo will not be able to pick it up = no deadlock.
**	- I print the status ("is eating...")
**	- The philosopher eats for <time_to_eat> milliseconds;
*/
void	make_philo_eat(t_philo *philo)
{ 
	// if (philo->id % 2 == 0)
	// {
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_status(philo, "has taken the left fork", GREEN);
	// 	pthread_mutex_lock(philo->right_fork);
	// 	print_status(philo, "has taken the right fork", GREEN);
	// }
	// else
	// {
	// 	pthread_mutex_lock(philo->right_fork);
	// 	print_status(philo, "has taken the right fork", GREEN);
	// 	pthread_mutex_lock(philo->left_fork);
	// 	print_status(philo, "has taken the left fork", GREEN);
	// }
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken the left fork", GREEN);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken the right fork", GREEN);

	
	print_status(philo, "is eating 🤤", PURPLE);
	philo->last_meal_eaten = get_time();
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->all_meals);
	philo->nb_meals_to_eat--;
	philo->data->count_meals++;
	pthread_mutex_unlock(&philo->data->all_meals);
	// printf("Le philo %d a mangé %d fois.\n", philo->id + 1, \
	// 	philo->data->nb_times_must_eat - philo->nb_meals_to_eat);
	// if (philo->id % 2 == 0)
	// {
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	pthread_mutex_unlock(philo->right_fork);
	// }
	// else
	// {
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	// }
}
