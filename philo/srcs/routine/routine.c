/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 18:29:58 by msanjuan         ###   ########.fr       */
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
		if (philo->has_eaten == false)
			make_philo_eat(philo);
		else if (philo->has_eaten == true && philo->has_slept == false)
			make_philo_sleep(philo);
		else if (philo->has_slept == true && philo->has_thought== false)
			make_philo_think(philo);
		else if (philo->has_eaten == true && philo->has_slept == true \
			&& philo->has_thought == true)
			reset_status(philo);
		// if (i == philo->data->nb_times_must_eat)
		// 	return (SUCCESS);
		i++;
	}
	return (SUCCESS);
}
