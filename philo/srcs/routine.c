/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/06 20:14:16 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void* routine(void *arg)
{
	t_philo			*philo;
	int				i;

	i = 1;
	philo = arg;

	printf("bonjour\n");
	printf(" nb de fois où il mange %d\n", philo->data->nb_times_must_eat);
	while (philo->is_dead == false || i <= philo->data->nb_times_must_eat)
	{
		// printf("numero du philo : %d | nb de fois où il mange %d\n", philo->id, philo->data->nb_times_must_eat);
		// if (data->philo_struct->has_eaten == false)
			make_philo_eat(philo);
		// else if (data->philo_struct->has_eaten == true)
		// 	make_philo_sleep(data->philo_struct, data);
		// else if (data->philo_struct->has_slept == true)
		// 	make_philo_think(data->philo_struct, data);
		// else if (data->philo_struct->has_eaten == true \
		// 	&& data->philo_struct->has_slept == true \
		// 	&& data->philo_struct->has_thought == true)
		// 	reset_status(data->philo_struct);
		// if (data->philo_struct->is_dead == true) // Probleme : prend trop de tps, à optimiser /!\.
		// 	stop_simulation(data, data->philo_struct);
		// if (i == data->nb_times_must_eat)
		// {
		// 	end_simulation(data);
		// 	exit(1);
		// }
		printf("le i de la boucle grr : %d\n", i);
		i++;
	}
	return (SUCCESS);
}
