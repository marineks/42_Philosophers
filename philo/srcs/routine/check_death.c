/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:43:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/17 14:32:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	check_time_of_death(struct s_philo *philo)
{
	long int	current;

	current = get_time();
	pthread_mutex_lock(&philo->data->last_meal);
	if (current - philo->last_meal_eaten > philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->death);
		philo->data->someone_died = true;
		pthread_mutex_unlock(&philo->data->death);
		pthread_mutex_lock(&philo->data->print);
		printf("%s%ld ms \t | %d died 😵\n%s", RED, \
			(current - philo->data->start_time), philo->id + 1, RESET);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->last_meal);
}

/*
*	As the philosophers are not allowed to communicate with each other,
*	we must check the eventuality of their death in the main thread.
*/
int	monitor_death(t_data *data)
{
	int	i;

	i = 0;
	usleep((data->time_to_die * 1000) / 2);
	while (1)
	{
		pthread_mutex_lock(&data->all_meals);
		if (data->count_meals == data->total_meal)
		{
			return (SUCCESS);
			pthread_mutex_unlock(&data->all_meals);
		}
		pthread_mutex_unlock(&data->all_meals);
		check_time_of_death(&(data->philo[i]));
		if (data->someone_died == true)
			return (FAILURE);
		i++;
		if (i == data->nb_of_philos - 1)
			i = 0;
		usleep(10);
	}
	return (SUCCESS);
}
