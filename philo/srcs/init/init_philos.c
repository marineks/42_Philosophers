/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:17:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 17:36:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	init_simulation(t_data *data, char **argv)
{
	data->nb_of_philos = ft_atoi(argv[1]);
	init_forks(data);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->count_meals = 0;
	data->someone_died = false;
	if (argv[5])
	{
		data->nb_times_must_eat = ft_atoi(argv[5]);
		data->total_meal = data->nb_of_philos * data->nb_times_must_eat;
		data->option_on = true;
	}
	else
	{
		data->option_on = false;
		data->nb_times_must_eat = -1;
	}
	data->start_time = get_time();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->last_meal, NULL);
	pthread_mutex_init(&data->all_meals, NULL);
}

t_philo	init_one_philo(t_philo philo, t_data *data, pthread_t philo_thr, int i)
{
	philo.thread = philo_thr;
	philo.is_dead = false;
	philo.id = i;
	philo.data = data;
	philo.nb_meals_to_eat = data->nb_times_must_eat;
	philo.last_meal_eaten = philo.data->start_time;
	philo.left_fork = attribute_forks(data, 'L', i);
	if (data->nb_of_philos > 1)
		philo.right_fork = attribute_forks(data, 'R', i);
	return (philo);
}