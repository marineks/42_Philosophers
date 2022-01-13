/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 18:30:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	Après avoir mangé et dormi, le philosophe doitpenser tant qu'il n'a pas
**  deux fourchettes pour remanger 
*/
void	make_philo_think(t_philo *philo)
{
	philo->data->elapsed_time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->print);
	printf("\033[1;33m%ld ms | %d is thinking 🤔\n\033[0m", philo->data->elapsed_time, philo->id + 1);
	philo->has_thought = true;
	pthread_mutex_unlock(&philo->data->print);
}

// void	make_philo_think(t_philo *philo)
// {
// 	pthread_mutex_lock(&data->mutex);
// 	printf("Test \n");
// 	usleep(data->);
//     gettimeofday (&end, NULL);
// 	data->elapsed_time = get_time(end);
// 	printf("Time in milliseconds: %ld milliseconds\n", data->elapsed_time);
// 	pthread_mutex_unlock(&data->mutex);
// }