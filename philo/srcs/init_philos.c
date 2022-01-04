/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:17:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/04 17:35:08 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_simulation(t_data *data, char **argv)
{
	struct timeval	start;
	
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_times_must_eat = ft_atoi(argv[5]);
	else
		data->nb_times_must_eat = -1;
	pthread_mutex_init(&data->mutex, NULL);
	gettimeofday(&start, NULL);
	data->elapsed_time = get_time(start);
}

void	init_one_philo(t_philo *philo, pthread_t *philo_thr, int id)
{
	philo[id].thread = philo_thr;
	philo[id].id = id;
	philo[id].is_dead = false;
	philo[id].has_eaten = false;
	philo[id].has_slept = false;
	philo[id].has_thought = false;
	// initialiser les mutex ici je pense
}