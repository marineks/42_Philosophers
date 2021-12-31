/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 10:17:00 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/31 14:42:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_philos(t_data *data, char **argv)
{
	data->nb_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_times_must_eat = ft_atoi(argv[5]);
	else
		data->nb_times_must_eat = 0;
}

int	create_threads(t_data *data)
{
	data->philo = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < data->nb_of_philos)
	{
		if (pthread_create(&data->philo[i], NULL, &routine, NULL) != SUCCESS)
			return (FAILURE);
		printf("Thread created\n");
		i++;
	}
	while (j < data->nb_of_philos)
	{
		if (pthread_join(data->philo[j], NULL) != SUCCESS)
			return (FAILURE);
		printf("Thread joined\n");
		j++;
	}
	return (SUCCESS);
}