/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:30:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/11 21:57:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	init_forks(t_data *data)
{
	int i;

	data->forks = ft_calloc(data->nb_of_philos, sizeof(pthread_mutex_t));
	i = 0;
	while (i < data->nb_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		printf("Fork num %d created\n", i);
		i++;
	}
}

/*
**	 Every philosopher has one fork but needs two to eat. As such they need
**	 to steal their neighbour's fork. 
**	 In this function, the left fork (L) is the one the philo has.
**	 Therefore, the right fork (R) is going to be the next philo's. (i + 1)
**	 In the event where it is the last philo, there is no "i + 1", so it
**	 will take the first philo's fork (aka full circle).
*/
pthread_mutex_t	*attribute_forks(t_data *data, char fork, int i)
{
	if (fork == 'L')
		return (&data->forks[i]);
	else
	{
		if (i + 1 == data->nb_of_philos)
			return (&data->forks[0]);
		else
			return (&data->forks[i + 1]);
	}
}