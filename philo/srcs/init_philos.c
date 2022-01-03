/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:17:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/03 14:43:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_simulation(t_data *data, char **argv)
{
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_times_must_eat = ft_atoi(argv[5]);
	else
		data->nb_times_must_eat = -1;
	// pthread_mutex_init(&data->mutex, NULL);
}

void	init_one_philo(int id)
{
	t_philo philo;

	philo.id = id;
	philo.is_dead = false;
	philo.has_eaten = false;
	philo.has_slept = false;
	philo.has_thought = false;
	// initialiser les mutex ici je pense
}