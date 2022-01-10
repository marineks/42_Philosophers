/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/10 15:59:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	make_philo_eat(t_philo *philo)
{
	philo->data->elapsed_time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms | %d is eating 🤤\n", philo->data->elapsed_time, philo->id + 1);
	philo->has_eaten = true;
	pthread_mutex_unlock(&philo->data->print);
	usleep(philo->data->time_to_eat * 1000);
}