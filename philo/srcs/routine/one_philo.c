/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:57:39 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 17:58:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	manage_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork", GREEN);
	pthread_mutex_unlock(philo->left_fork);
	usleep(philo->data->time_to_die * 1000);
	printf("%s%d ms \t | %d died 😵\n%s", RED, philo->data->time_to_die,\
	philo->id, RESET);
}