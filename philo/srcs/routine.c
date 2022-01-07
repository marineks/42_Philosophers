/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:21:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/07 23:11:57 by msanjuan         ###   ########.fr       */
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
	// printf("nb times eat : %d | id philo : %d\n", philo->data->nb_times_must_eat, philo->id);
	while (i < 3 || philo->is_dead == false || i <= philo->data->nb_times_must_eat)
	{
		usleep(50000);
		printf(" DEDANS nb times eat : %d | id philo : %d\n", philo->data->nb_times_must_eat, philo->id);
		// if (philo->id == 0)
		// 	printf("Je suis le 1er thread : %d\n", (philo->id));
		// else if (philo->id == 1)
		// 	printf("Thread 2 : %d\n", (philo->id));
		// else
		// 	printf("id de merde: %d | avec = 1 = %d\n", philo->id, philo->id);
		// printf("numero du philo : %d\n", philo->id + 1);
		if (philo->has_eaten == false)
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
		if (i == philo->data->nb_times_must_eat)
			return (0);
		printf("le i de la boucle grr : %d\n", i);
		i++;
	}
	// pthread_mutex_unlock(&philo->data->loop);
	return (SUCCESS);
}
