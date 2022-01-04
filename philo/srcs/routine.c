/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/04 17:28:06 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void* routine(void *arg)
{
	t_philo			*philo;
	int				i;

	i = 1;
	philo = (t_philo *)arg;
	while (philo->is_dead == false || i <= philo->data->nb_times_must_eat)
	{
		if (philo->has_eaten == false)
			make_philo_eat(philo, philo->data);
		else if (philo->has_eaten == true)
			make_philo_sleep(philo, philo->data);
		else if (philo->has_slept == true)
			make_philo_think(philo, philo->data);
		else if (philo->has_eaten == true && philo->has_slept == true \
			&& philo->has_thought == true)
			reset_status(philo);
		if (philo->is_dead == true) // Probleme : prend trop de tps, à optimiser /!\.
			stop_simulation(philo->data, philo);
		if (i == philo->data->nb_times_must_eat)
		{
			end_simulation(philo->data);
			exit(1);
		}
		i++;
	}
	return (SUCCESS);
}
