/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:30:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/11 18:01:35 by msanjuan         ###   ########.fr       */
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

pthread_mutex_t	attribute_forks(t_data *data, char fork)
{
	
}