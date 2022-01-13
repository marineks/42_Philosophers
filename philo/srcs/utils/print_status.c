/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:58:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:30:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"


void	print_status(t_philo *philo, char *str, char *color)
{
	
	pthread_mutex_lock(&philo->data->print);
	printf("%s%ld ms | %d %s\n%s", 
		color, (get_time() - philo->data->start_time), philo->id + 1, str, RESET);
	pthread_mutex_unlock(&philo->data->print);
}

// void	print_status(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->print);
// 	printf("\033[0;32m%ld ms | %d has a taken the left fork\n\033[0m", get_time() - philo->data->start_time, philo->id + 1);
// 	printf("\033[0;32m%ld ms | %d has a taken the right fork\n\033[0m", get_time() - philo->data->start_time, philo->id + 1);
// 	printf("\033[0;35m%ld ms | %d is eating 🤤\n\033[0m", get_time() - philo->data->start_time, philo->id + 1);
// 	philo->has_eaten = true;
// 	// philo->nb_times_must_eat--;
// 	// printf("Le philo %d a mangé %d fois.\n", philo->id, philo->nb_times_must_eat);
// 	pthread_mutex_unlock(&philo->data->print);
// }