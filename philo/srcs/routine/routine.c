/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 15:13:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void* routine(void *arg)
{
	t_philo			*philo;
	int				i;

	philo = arg;
	i = 0;
	if (philo->id % 2 == 0)
		usleep(10000);
	while (i <= philo->data->nb_times_must_eat)
	{
		// printf("Le philo %d a mangé %d fois. Il reste %d routines\n", \
			// philo->id, philo->nb_times_must_eat, philo->data->nb_times_must_eat);
			make_philo_eat(philo);
			make_philo_sleep(philo);
			make_philo_think(philo);
			// reset_status(philo);
		// if (i == philo->data->nb_times_must_eat)
		// 	return (SUCCESS);
		i++;
	}
	return (SUCCESS);
}
