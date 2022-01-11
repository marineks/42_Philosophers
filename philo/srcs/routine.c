/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/10 16:04:23 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void* routine(void *arg)
{
	t_philo			*philo;
	int				i;

	philo = arg;
	// pthread_mutex_lock(&philo->data->loop);
	i = 0;
	while (philo->is_dead == false || i <= philo->data->nb_times_must_eat)
	{
		if (philo->has_eaten == false)
			make_philo_eat(philo);
		else if (philo->has_eaten == true)
			make_philo_sleep(philo);
		else if (philo->has_slept == true)
			make_philo_think(philo);
		else if (philo->has_eaten == true \
			&& philo->has_slept == true \
			&& philo->has_thought == true)
			reset_status(philo);
		if (philo->is_dead == true) // Probleme : prend trop de tps, à optimiser /!\.
			stop_simulation(philo);
		if (i == philo->data->nb_times_must_eat)
		{
			end_simulation(philo->data);
			exit(1);
		}
		if (i == philo->data->nb_times_must_eat)
			return (0);
		i++;
	}
	// pthread_mutex_unlock(&philo->data->loop);
	return (SUCCESS);
}
