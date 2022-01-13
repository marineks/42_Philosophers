/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 18:30:08 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"


void	print_status(t_philo *philo)
{
	philo->data->elapsed_time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("\033[0;32m%ld ms | %d has a taken the left fork\n\033[0m", philo->data->elapsed_time, philo->id + 1);
	printf("\033[0;32m%ld ms | %d has a taken the right fork\n\033[0m", philo->data->elapsed_time, philo->id + 1);
	printf("\033[0;35m%ld ms | %d is eating 🤤\n\033[0m", philo->data->elapsed_time, philo->id + 1);
	philo->has_eaten = true;
	// philo->nb_times_must_eat--;
	// printf("Le philo %d a mangé %d fois.\n", philo->id, philo->nb_times_must_eat);
	pthread_mutex_unlock(&philo->data->print);
}
void	make_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
