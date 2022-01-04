/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:45:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/04 17:27:34 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	create_threads(t_data *data)
{
	int		i;
	t_philo philo_struct[255];

	i = 1;
	data->philo = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	while (i <= data->nb_of_philos)
	{
		printf("%d\n", i);
		init_one_philo(philo_struct, &data->philo[i], i);
		if (pthread_create(&data->philo[i], NULL, &routine, (philo_struct + i)) != SUCCESS)
			return (FAILURE);
		printf("Thread created\n");
		i++;
	}
	i = 1;
	while (i <= data->nb_of_philos)
	{
		if (pthread_join(data->philo[i], NULL) != SUCCESS)
			return (FAILURE);
		printf("Thread joined\n");
		i++;
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