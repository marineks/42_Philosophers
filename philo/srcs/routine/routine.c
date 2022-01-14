/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 17:58:37 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void* routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->nb_of_philos > 1)
	{
		if (philo->id % 2 == 0)
			usleep(10000);
		while ((is_alive(philo) == SUCCESS
			&& philo->data->option_on == false)
			|| (is_alive(philo) == SUCCESS
			&& philo->nb_meals_to_eat
			&& philo->data->option_on == true))
		{
			make_philo_eat(philo);
			make_philo_sleep(philo);
			make_philo_think(philo);
		}
	}
	else
		manage_one_philo(philo);
	return (SUCCESS);
}
