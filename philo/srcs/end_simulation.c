/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:40:41 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 17:59:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	end_simulation(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->print);
	i = 0;
	while (i < data->nb_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		printf("Fork num %d deleted\n", i);
		i++;
	}
	free(data->forks);
	free(data->philo_thr);
	// free(data);
}