/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:45:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/10 15:44:37 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	create_threads(t_data *data)
{
	t_philo	philo_struct[255];
	int		i;

	i = 0;
	data->philo_thr = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	while (i < data->nb_of_philos)
	{
		philo_struct[i].data = data;
		philo_struct[i].id = i;
		init_one_philo(philo_struct + i, data->philo_thr[i], i);
		if (pthread_create(&data->philo_thr[i], NULL, &routine, &philo_struct[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_join(data->philo_thr[i], NULL) != SUCCESS)
			return (FAILURE);
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