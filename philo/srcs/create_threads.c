/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:45:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/03 17:02:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void* routine(void *arg) // void * et on caste apres
{
	t_data 			*data;
	t_philo			philo;
	int				i;

	i = 1;
	data = (t_data *)arg;
	while (philo.is_dead == false || i <= data->nb_times_must_eat)
	{
		if (philo.has_eaten == false)
			make_philo_eat(&philo);
		else if (philo.has_eaten == true)
			make_philo_sleep(&philo, data);
		else if (philo.has_slept == true)
			make_philo_think(&philo);
		else if (philo.has_eaten == true && philo.has_slept == true \
			&& philo.has_thought == true)
			reset_status(&philo);
		if (philo.is_dead == true) // Probleme : prend trop de tps, à optimiser /!\.
			stop_simulation(data, &philo);
		if (i == data->nb_times_must_eat)
		{
			end_simulation(data);
			exit(1);
		}
		i++;
	}
	return (SUCCESS);
}

int	create_threads(t_data *data)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	data->philo = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	while (i <= data->nb_of_philos)
	{
		init_one_philo(i);
		if (pthread_create(&data->philo[i], NULL, &routine, data) != SUCCESS)
			return (FAILURE);
		printf("Thread created\n");
		i++;
	}
	while (j <= data->nb_of_philos)
	{
		if (pthread_join(data->philo[j], NULL) != SUCCESS)
			return (FAILURE);
		printf("Thread joined\n");
		j++;
	}
	return (SUCCESS);
}


	// pthread_mutex_lock(&data->mutex);
	// gettimeofday(&begin, NULL);
	// start = get_time(begin);
	// printf("Test \n");
	// usleep(30000);
    // gettimeofday (&end, NULL);
	// data->elapsed_time = get_time(end) - start;
	// printf("Time in milliseconds: %ld milliseconds\n", data->elapsed_time);
	// pthread_mutex_unlock(&data->mutex);