/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:17:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/11 21:58:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_simulation(t_data *data, char **argv)
{
	data->nb_of_philos = ft_atoi(argv[1]);
	init_forks(data);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_times_must_eat = ft_atoi(argv[5]);
	else
		data->nb_times_must_eat = -1;
	pthread_mutex_init(&data->print, NULL);
	data->start_time = get_time();
}

t_philo	init_one_philo(t_philo philo, t_data *data, pthread_t philo_thr, int i)
{
	philo.thread = philo_thr;
	philo.is_dead = false;
	philo.has_eaten = false;
	philo.has_slept = false;
	philo.has_thought = false;
	philo.id = i;
	philo.data = data;
	philo.left_fork = attribute_forks(data, 'L', i);
	philo.right_fork = attribute_forks(data, 'R', i);
	return (philo);
}